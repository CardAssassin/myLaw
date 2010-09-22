  <head>
    <title>Evaluations</title>
    <style type="text/css">
      body 
      {
        padding-top:    25pt;
        padding-bottom: 25pt;
        padding-left:   15pt;
        padding-right:  15pt;
        margin-right:   20pt;
        margin-bottom:  25pt;
        margin-top:     25pt;

        font-family:    Arial;
      }
      table 
      {
        border: 1pt solid black; 
        margin: 0pt;
        padding: 0pt;
      }
      td
      {
        width: 100pt;
        border: 1pt solid gray;  
        margin: 0 pt;
        padding: 3pt;
      }
      
    </style>
  </head>
  <body>

  <?php
  if($print['course']){
    print '<h1>' . $print['course']->title . '</h1>';
    print '<h2>' . theme('username', (object)array('name' => $print['course']->primary_instructor_nuid), 'nolink') . '</h2>';
  }
  ?>

  <table>
  <tr>
    <?php
    if($print['can_view_student_names']){
      print '<td>Student Name</td>';
    }
    ?>
    <td>Exam Number</td>
    <?php
    if($print['can_view_exam_type']){
      print '<td>Type</td>';
    }
    if($print['can_view_evaluations']){
      print '<td>Grade</td>';
    }
    ?>
    <td>Last Edited</td>
    <td>Final</td>
  </tr>
  <?php
    foreach($print['evaluations'] as $evaluation){
      print '<tr>';
      if($print['can_view_student_names']){
        print '<td>'.$evaluation['student'].'</td>';
      }
      print '<td>'.$evaluation['exam_number'].'</td>';
      if($print['can_view_exam_type']){
        print '<td>'.$evaluation['exam_type'].'</td>';
      }
      if($print['can_view_evaluations']){
        print '<td>'.$evaluation['grade'].'</td>';
      }
      print '<td>'.$evaluation['last_edited_count'].' revisions<br>'.$evaluation['last_edited_date'].'<br>'.$evaluation['last_edited_user'].'</td>';
      print '<td>'.$evaluation['final_count'].' submissions<br>'.$evaluation['final_date'].'<br>'.$evaluation['final_user'].'</td>';
      print '</tr>';
    }
  ?>
  </table>


  </body>
</html>

