<?php
/**
 * @file
 * Alpha's theme implementation to display a single Drupal page.
 */
?>
<div class="ad-banner"><div class="ad-banner-inner"><h1>Tamba S. Lamin added this during IRS DEMO</h1></div></div>
<div<?php print $attributes; ?>>
  <?php if (isset($page['header'])) : ?>
    <?php print render($page['header']); ?>
  <?php endif; ?>

  <?php if (isset($page['content'])) : ?>
    <?php print render($page['content']); ?>
  <?php endif; ?>

  <?php if (isset($page['footer'])) : ?>
    <?php print render($page['footer']); ?>
  <?php endif; ?>
</div>
