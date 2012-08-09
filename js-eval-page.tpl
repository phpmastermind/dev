<!-- ______________________ HEADER _______________________ -->

<div id="header">
  <div class="container clearfix">
    <div id="logo">
		<?php if ($logo): ?>
        <a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        <?php endif; ?>
        <?php if ($site_name || $site_slogan): ?>
        <div class="clearfix">
        <?php if ($site_name): ?>
        <span id="site-name"><a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a></span>
        <?php endif; ?>
        <?php if ($site_slogan): ?>
        <span id="slogan"><?php print $site_slogan; ?></span>
        <?php endif; ?>
        </div><!-- /site-name-wrapper -->
        <?php endif; ?>
    </div>
    <div id="header-right">
    	<div class="header-right-top">
    	<a id="login-btn" href="<?php print base_path(); ?>?q=user">Login</a>
        <a id="signup-btn" href="<?php print base_path(); ?>?q=signup">Sign Up</a>
        </div>
        <div id="eva-accelerator"><img src="<?php print base_path() . drupal_get_path('theme', 'jaspersoft')?>/images/eva_accelerator.png" /></div>
    </div>
  </div> <!-- /header-container -->    
</div> <!-- /header -->

<!-- ______________________ MAIN WRAPPER _______________________ -->
<div id="main-wrapper">

  <!-- ______________________ MAIN _______________________ -->
  <div id="main" class="main row clearfix grid12-12">	
    <div id="main-left-top-bg"></div>
    <div id="main-right-top-bg"></div>
  <!-- ______________________ NAVIGATION _______________________ -->
  
  <?php if (!empty($main_menu)): ?>
    <div id="navigation"><!-- navigation -->
        <?php print theme('links', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'main-menu')))); ?>
        <!--<a title="Subscribe to magazeen RSS" class="rss" href="">Subscribe</a>-->
    </div> <!-- /navigation -->
  <?php endif;?>

  <!-- ______________________ Main Content _______________________ -->
  <div id="main-content-wrapper" class="row container main_view">
  <div id="main-content-wrapper-top"></div>
    <div class="main-content-wrapper-content">
			<?php if ($page['highlighted']): ?>
            <div id="highlighted">
			<?php print render($page['highlighted']); ?>
            </div>
			<?php endif; ?>
       
			<?php if ($messages): ?>
            <div id="console" class="clearfix">
			<?php print $messages; ?>
            </div>
            <?php endif; ?>
     
            <?php if ($page['help']): ?>
            <div id="help">
            <?php print render($page['help']); ?>
            </div>
            <?php endif; ?>
            
            <?php if ($action_links): ?>
            <ul class="action-links">
			<?php print render($action_links); ?>
            </ul>
			<?php endif; ?>
            
            <?php print render($title_prefix); ?>
            <?php if ($title): ?>
            <h1 class="title"><?php print $title ?></h1>
            <?php endif; ?>
            <?php print render($title_suffix); ?>
            
            <?php if ($tabs): ?><?php print render($tabs); ?><?php endif; ?>
            
            <?php print render($page['content']); ?>
            
            <?php if ($feed_icons): ?><?php print $feed_icons; ?><?php endif; ?>
     	</div>
  <div id="main-content-wrapper-btm"></div>
  </div> <!-- /Main Content Wrapper -->	
  
  <div id="main-left-btm-bg"></div>
  <div id="main-right-btm-bg"></div>
  
  </div><!-- /main -->
</div> <!-- /main wrapper -->

<!-- ______________________ FOOTER _______________________ -->

<div class="footer-wrapper full-width" id="footer-wrapper">
  
  <?php if ($page['footer']): ?>	
  <div class="footer row grid12-12" id="footer">
    <?php print render($page['footer']); ?>
  </div><!-- /footer -->
  <?php endif; ?>

</div> <!-- /main wrapper -->

  <!-- ______________________ SECONDARY NAVIGATION _______________________ -->

  <?php if (!empty($secondary_menu)): ?>
    <div id="snavigation"><!-- snavigation -->
      <div class="container clearfix">
        <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('class' => array('secondary-menu', 'links', 'clearfix')))); ?>
      </div> <!-- /snavigation-container -->
    </div> <!-- /snavigation -->
  <?php endif;?>


