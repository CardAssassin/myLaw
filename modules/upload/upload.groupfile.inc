<?php


function upload_groupfiles($node){
  $path = file_directory_path().'/group-'.$node->nid;
  file_check_directory($path, FILE_CREATE_DIRECTORY);
  $handler = opendir($path);

  $rows = array();
  $attributes = array();
  while($file = readdir($handler)){
    if($file != '.' && $file != '..'){
      
      $filepath = $path.'/'.$file;

//f.filesize, f.timestamp, n.nid, n.title
//INNER JOIN {upload} u on u.fid = f.fid INNER JOIN {node} n on n.nid = u.nid 
      $query = "SELECT * FROM {files} f WHERE f.filepath = '%s'";
      $file_data = db_fetch_object(db_query($query, $filepath));
      $query = "SELECT DISTINCT(n.nid), n.title FROM {node} n INNER JOIN {upload} u on u.nid = n.nid WHERE u.fid = %d ORDER BY n.title";
      $node_results = db_query($query, $file_data->fid);
      $node_links = '';
      while($node_data = db_fetch_object($node_results)){
        if($node_links != ''){
          $node_links .= '<br/>';
        }
        $node_links .= l($node_data->title, 'node/'.$node_data->nid);
      }
      $rows[] = array(
        'filename' => l($file, file_create_url($filepath), array('attributes' =>array('target' => '_blank'))),
        'size' => ceil($file_data->filesize/1000). " kb",
        'date' => array(
          'data' => format_date($file_data->timestamp, 'small'),
          'timestamp' => $file_data->timestamp,
        ),
        'node' => $node_links,
      );
    }  
  }
  
  $header[] = array(
    'data' => 'File',
    'field' => 'filename',
  );
  $header[] = array(
    'data' => 'Size',
    'field' => 'size',
  );
  $header[] = array(
    'data' => 'Date',
    'field' => 'date',
  );
  $header[] = array(
    'data' => 'Attached To',
    'field' => 'node',
  );


  _upload_groupfiles_sort($header, $rows);

  return theme('table', $header, $rows, $attributes);
}


//sorting function for the og_group_access_membership
function _upload_groupfiles_sort($header, &$rows){
  $sort = tablesort_get_sort($header);
  $order = tablesort_get_order($header);
  usort($rows, "_upload_groupfiles_sort_".$order['sql']."_".$sort);
}

//helper function for _og_group_access_files_sort()
function _upload_groupfiles_sort_filename_asc($a, $b){
  return($a['filename'] > $b['filename']);
}

//helper function for _og_group_access_files_sort()
function _upload_groupfiles_sort_filename_desc($a, $b){
  return($a['filename'] < $b['filename']);
}

//helper function for _og_group_access_files_sort()
function _upload_groupfiles_sort_size_asc($a, $b){
  if($a['size'] == $b['size']){
    return _upload_groupfiles_sort_filename_asc($a, $b);
  }
  return($a['size'] > $b['size']);
}

//helper function for _og_group_access_files_sort()
function _upload_groupfiles_sort_size_desc($a, $b){
  if($a['size'] == $b['size']){
    return _upload_groupfiles_sort_filename_asc($a, $b);
  }
  return($a['size'] < $b['size']);
}

//helper function for _og_group_access_files_sort()
function _upload_groupfiles_sort_date_asc($a, $b){
  if($a['date']['timestamp'] == $b['date']['timestamp']){
    return _upload_groupfiles_sort_filename_asc($a, $b);
  }
  return($a['date']['timestamp'] > $b['date']['timestamp']);
}

//helper function for _og_group_access_files_sort()
function _upload_groupfiles_sort_date_desc($a, $b){
  if($a['date']['timestamp'] == $b['date']['timestamp']){
    return _upload_groupfiles_sort_filename_asc($a, $b);
  }
  return($a['date']['timestamp'] < $b['date']['timestamp']);
}

//helper function for _og_group_access_files_sort()
function _upload_groupfiles_sort_node_asc($a, $b){
  if($a['node'] == $b['node']){
    return _upload_groupfiles_sort_filename_asc($a, $b);
  }
  return($a['node'] > $b['node']);
}

//helper function for _og_group_access_files_sort()
function _upload_groupfiles_sort_node_desc($a, $b){
  if($a['node'] == $b['node']){
    return _upload_groupfiles_sort_filename_asc($a, $b);
  }
  return($a['node'] < $b['node']);
}

