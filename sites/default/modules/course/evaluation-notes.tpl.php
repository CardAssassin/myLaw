  <head>
    <title>Evaluation Notes</title>
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
  <body>

  <div id="header1">
        <div id="schoolname">Northeastern University School of Law</div>
        <div id="address">
          400 Huntington Avenue<br/>
          Boston, Massachusetts 02115
        </div>
        <br><br>
        <div id="courseevaluation">
          EVALUATION NOTES TO STUDENT
        </div>
   </div>
   <hr>
      <table border=0 width=100% cellpadding=0 cellspacing=0 >
        <tr>
          <td class="data-title">Student:</td>
          <td ><?php print $print['student'] ?></td>
        </tr>
        <tr>
          <td class="data-title">Exam #:</td>
          <td ><?php print $print['exam_number'] ?></td>
        </tr>
        <tr>
          <td class="data-title">Course Title:</td>
          <td><?php print $print['course_title'] ?></td>
        </tr>
        <tr>
          <td class="data-title">Course ID:</td>
          <td><?php print $print['course_identification'] ?></td>
        </tr>
        <tr>
          <td class="data-title">Credits:</td>
          <td><?php print $print['credits'] ?></td>
        </tr>
        <tr>
          <td class="data-title">Term:</td>
          <td colspan=3><?php print $print['registration_term_desc'] ?></td>
        </tr>
        <tr>
          <td class="data-title">Instructor<?php if($print['secondary_instructor'] != ''){ print 's';} ?>:</td>
          <td colspan=3><?php print $print['primary_instructor'] ?></td>
        </tr>
        <?php if($print['secondary_instructor'] != ''): ?>
        <tr>
          <td>&nbsp;</td>
          <td colspan=3><?php print $print['secondary_instructor'] ?></td>
        </tr>
        <?php endif; ?>
        <tr>
          <td class="data-title">Grade:</td>
          <td><?php print $print['grade'] ?></td>
        </tr>
      </table>
    <hr>
    <span class="section-title">Course Description:</span>
    <div class="section">
      <?php print $print['course_desc'] ?>
    </div>
    <hr>
    <?php if($print['evaluation_desc'] != '' && $print['evaluation_desc'] != '<p></p>'): ?>
    <span class="section-title">Evaluation Description:</span>
    <div class="section">
      <?php print $print['evaluation_desc'] ?>
    </div>
    <hr>
    <?php endif; ?>
    <span class="section-title">Notes:</span>
    <div class="section">
      <?php print $print['notes'] ?>
    </div>
    <hr>
  </body>
</html>

