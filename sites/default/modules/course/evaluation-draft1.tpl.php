<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
<!--xmlns="http://www.w3.org/1999/xhtml" lang="<?php  print $print['language'] ?>" xml:lang="<?php  print $print['language'] ?>"-->
  <head>
    <title>Evaluation <?php  print $print['title'] ?></title>
    <!--?php  print $print['head'] ?-->
    <!--?php  print $print['scripts'] ?-->
    <!--?php  print $print['robots_meta'] ?-->
    <!--?php  print $print['base_href'] ?-->
    <!--?php  print $print['favicon'] ?-->
    <!--?php  print $print['css'] ?-->
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
      
      #header1
      {
        text-align:    center;
        font-family:    Arial;
        font-weight:   bold;
      }

      #schoolname
      {
        font-size:     18pt;
      }

      #address
      {
        font-size:     14pt;
      }

      #courseevaluation
      {
        padding-top     20px;
        font-size:     14pt;
      }

      .section
      {
        padding-left:  10px;
        font-size:     12pt;
      }

      .section-title
      {
        font-weight:   bold;
        font-size:     12pt;
      }
      
      table td.header-name
      {
        text-align: right;
        border: 1pt solid black;
      }

      table td.data-title
      { 
        width:       120px;
        font-weight: bold;
      }
    </style>
  </head>
  <!--body background='https://<?php print $_SERVER['SERVER_NAME'] . base_path() . file_directory_path() ?>/Draft.jpg'-->
  <body >

  <div id="header1">
        <div id="schoolname">Northeastern University School of Law</div>
        <div id="address">
          400 Huntington Avenue<br/>
          Boston, Massachusetts 02115
        </div>
        <br><br>
        <div id="courseevaluation">
          COURSE EVALUATION - DRAFT
        </div>
   </div>
   <hr>
      <table border=0 width=100% cellpadding=0 cellspacing=0 >
        <tr>
          <td class="data-title">Student:</td>
          <td ><?php 
                 if($print['can_view_student_names']) {
                   print $print['node']->student;
                 }
              ?>
          </td>
        </tr>
        <?php if($print['node']->exam_number != ''): ?>
        <tr>
          <td class="data-title">Exam #:</td>
          <td ><?php print $print['node']->exam_number ?></td>
        </tr>
        <?php endif; ?>
        <tr>
          <td class="data-title">Course Title:</td>
          <td><?php print $print['course']->title ?></td>
        </tr>
        <tr>
          <td class="data-title">Course ID:</td>
          <td><?php print $print['course']->course_number ?></td>
        </tr>
        <tr>
          <td class="data-title">Credits:</td>
          <td><?php print $print['course']->credits ?></td>
        </tr>
        <tr>
          <td class="data-title">Term:</td>
          <td colspan=3><?php print $print['course']->registration_term_desc ?></td>
        </tr>
        <tr>
          <td class="data-title">Instructor<?php if($print['course']->secondary_instructor_nuid != NULL){ print 's';} ?>:</td>
          <td colspan=3><?php print theme('username', (object)array('name' => $print['course']->primary_instructor_nuid), 'nolink', 1) ?></td>
        </tr>
        <?php if($print['course']->secondary_instructor_nuid != NULL): ?>
        <tr>
          <td>&nbsp;</td>
          <td colspan=3><?php print theme('username', (object)array('name' => $print['course']->secondary_instructor_nuid), 'nolink', 1) ?></td>
        </tr>
        <?php endif; ?>
        <tr>
          <td class="data-title">Grade:</td>
          <td><?php print $print['node']->grade ?></td>
        </tr>
      </table>
    <hr>
    <span class="section-title">Course Description:</span>
    <div class="section">
      <?php print $print['course']->body ?>
    </div>
    <hr>
    <?php if($print['course']->evaluation_description != '' && $print['course']->evaluation_description != '<p></p>'):?>
    <span class="section-title">Evaluation Description:</span>
    <div class="section">
      <?php print $print['course']->evaluation_description ?>
    </div>
    <hr>
    <?php endif ?>
    <span class="section-title">Evaluation:</span>
    <div class="section">
      <?php print $print['node']->body ?>
    </div>
    <hr>
      <table border=0 width=100% cellpadding=0 cellspacing=0 >
      <tr height=50>
        <td class="data-title">
          Instructor Signature<?php if($print['course']->secondary_instructor_nuid != NULL){print 's';} ?>:
        </td>
        <td >
          <br/><br/><br/><br/>
        </td>
      </tr>
      <tr>
        <td class="data-title">Date:</td>
        <td ><?php print format_date($print['timestamp'], 'custom', 'F d, Y'); ?></td>
      </tr>
      </table>

  <br/>
  <br/>


  </body>
</html>

