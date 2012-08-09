	
<!--   <script src="modernizr-2.5.3.min.js"></script> -->
</head>
<body>
   <!--[if lt IE 7]><p class=chromeframe>Your browser is <em>ancient!</em> <a href="http://browsehappy.com/">Upgrade to a different browser</a> or <a href="http://www.google.com/chromeframe/?redirect=true">install Google Chrome Frame</a> to experience this site.</p><![endif]-->
  
<div id="container">Loading the player...</div>

<script type="text/javascript">
          jwplayer('container').setup(
          {
              id: 					'container',
              wmode: 				'transparent',
              icons: 				'true',
              allowscriptaccess: 	'always',
			  stretching: 			'exactfit',
              allownetworking: 		'all',
              file: 				'<?php echo $stream_dir.$videoname; ?>.mp4',				
              image: 				'<?php echo $s3url.$videoname; ?>.jpg',
              width: 				'<?php echo $video_width ?>', 
              height: 				'<?php echo $video_height ?>',
              controlbar: 			'bottom',
              dock: 				'false',
              provider:				'rtmp',
              streamer:				'rtmp://s3bh5cych70sat.cloudfront.net/cfx/st',
              autoStart : 			'true',
              modes: [{
              			type: 		'flash', 
              			src: 		'player.swf'},
                      {
                        type: 		'html5',
                        config: {
						file: 		'<?php echo $s3url.$videoname; ?>.mp4',
                         provider:	'video'
                        }
                      },
                      {
                        type: 		'download',
                        config: {
                        file: 		'<?php echo $s3url.$videoname; ?>.mp4',
                         provider:  'video'
                        }
                      }
              		]
          });
      </script>


</body>
</html>






  
<!--
  <div class="video-js-box">    
    <video class="video-js vjs-default-skin alignleft" width="640" height="360" controls preload="auto" autoplay poster="<?php echo $videoname ?>.jpg" data-setup="{}">
    	<source src="<?php echo $videoname ?>.mp4" type='video/mp4' />
		<source src="<?php echo $videoname ?>.webm" type='video/webm; codecs="vp8, vorbis"' />
		<source src="<?php echo $videoname ?>.ogg" type='video/ogg; codecs="theora, vorbis"' />      
    </video>
  </div>
-->

  <!-- Asynchronous Google Analytics snippet. Change UA-XXXXX-X to be your site's ID.
       mathiasbynens.be/notes/async-analytics-snippet -->

       
  <!-- <script src="http://vjs.zencdn.net/c/video.js"></script> -->
  
  <script>
    var _gaq=[['_setAccount','UA-33040831-1'],['_trackPageview']];
    (function(d,t){var g=d.createElement(t),s=d.getElementsByTagName(t)[0];
    g.src=('https:'==location.protocol?'//ssl':'//www')+'.google-analytics.com/ga.js';
    s.parentNode.insertBefore(g,s)}(document,'script'));
  </script>
</body>
</html>