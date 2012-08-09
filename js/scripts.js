jQuery(document).ready(function($) {	

//Set Default State of each portfolio piece
$(".paging").show();
$(".paging a:first").addClass("active");
    
//Get size of images, how many there are, then determin the size of the image reel.
var imageWidth = $(".window").width();
var imageSum = $(".image_reel .items").size();
var imageReelWidth = imageWidth * imageSum;

//Adjust the image reel to its new size
$(".image_reel").css({'width' : imageReelWidth});

//Paging + Slider Function
rotate = function(){	
    var triggerID = $active.attr("rel") - 1; //Get number of times to slide
    var image_reelPosition = triggerID * imageWidth; //Determines the distance the image reel needs to slide

    $(".paging a").removeClass('active'); //Remove all active class
    $active.addClass('active'); //Add active class (the $active is declared in the rotateSwitch function)
    
    //Slider Animation
    $(".image_reel").animate({ 
        left: -image_reelPosition
    }, 500 );
}; 

//Rotation + Timing Event
rotateSwitch = function(){
	
	$(".image_reel .items").each(function(i,el){
		//alert(i*imageWidth);
		$(el).css("left", i*imageWidth + "px");	
	});
			
    play = setInterval(function(){ //Set timer - this will repeat itself every 3 seconds
        $active = $('.paging a.active').next();
        if ( $active.length === 0) { //If paging reaches the end...
            $active = $('.paging a:first'); //go back to first
        }
        rotate(); //Trigger the paging and slider function
    }, 5000); //Timer speed in milliseconds (3 seconds)
};

rotateSwitch(); //Run function on launch

//On Hover
$(".image_reel .items").hover(function() {
    clearInterval(play); //Stop the rotation
}, function() {
    rotateSwitch(); //Resume rotation
});	

//On Click
$(".paging a").click(function() {	
    $active = $(this); //Activate the clicked paging
    //Reset Timer
    clearInterval(play); //Stop the rotation
    rotate(); //Trigger rotation immediately
    rotateSwitch(); // Resume rotation
    return false; //Prevent browser jump to link anchor
});

//On Click
$(".force-next a").click(function() {	
    $active = $('.paging a.active').next(); //Activate the clicked paging
	if ( $active.length === 0) { //If paging reaches the end...
            $active = $('.paging a:first'); //go back to first
    }
    //Reset Timer
    clearInterval(play); //Stop the rotation
    rotate(); //Trigger rotation immediately
    rotateSwitch(); // Resume rotation
    return false; //Prevent browser jump to link anchor
});	

//On Click
$(".force-previous a").click(function() {	
    $active = $('.paging a.active').prev(); //Activate the clicked paging
	if ( $active.length === 0) { //If paging reaches the end...
            $active = $('.paging a:last'); //go back to first
    }
    //Reset Timer
    clearInterval(play); //Stop the rotation
    rotate(); //Trigger rotation immediately
    rotateSwitch(); // Resume rotation
    return false; //Prevent browser jump to link anchor
});	

//Get size of images, how many there are, then determin the size of the image reel.
var frmWidth = $(".signup-form-container").width();
var frmSum = $(".steps-container .steps").size();
var frmReelWidth = frmWidth * frmSum;
//Adjust the image reel to its new size
$(".steps-container").css({'width' : frmReelWidth});

rotateform = function(callbackfunc){
	$(".steps-container .steps").each(function(i,el){
		//alert(i*imageWidth);
		$(el).css("left", i*frmReelWidth + "px");	
	});
	
	var locationhash = window.location.hash;
	//alert(locationhash);
	if(locationhash !="")
		$active = $(locationhash);
	else
		$active = $('.steps-container .active').next();
	
	//alert("active;" + $active[0].id );
	
	if ( $active.length === 0) { //If paging reaches the end...
		$active = $('.steps:first'); //go back to firs
	}
	
			
	var triggerID = $active.attr("rel") - 1; //Get number of times to slide
	if(triggerID > 0)
		$(".steps-prev").fadeIn();
			
    var image_reelPosition = triggerID * frmReelWidth; //Determines the distance the image reel needs to slide

    $(".steps").removeClass('active'); //Remove all active class
    $active.addClass('active'); //Add active class (the $active is declared in the rotateSwitch function)

    $(".steps-content-left").fadeOut(1000); //Remove all active class
	$("#step"+$active.attr("rel")+"-content").fadeIn(1000);
	
	$(".steps-next").hide(); //Remove all active class
	$("#step"+$active.attr("rel")+"_btn").fadeIn(1000);
	
     //Add active class (the $active is declared in the rotateSwitch function)
    
    //Slider Animation
    $(".steps-container").animate({ 
        left: -image_reelPosition
    }, 500 , callbackfunc );
}

rotateformback = function(callbackfunc){
	
	$active = $('.steps-container .active').prev();
	var triggerID = $active.attr("rel") - 1; //Get number of times to slide
	if(triggerID < 1)
		$(".steps-prev").fadeOut();
		
	var image_container_position = $(".steps-container").css('left');
    var image_reelPosition = parseInt(image_container_position) + frmReelWidth; //Determines the distance the image reel needs to slide

    $(".steps").removeClass('active'); //Remove all active class
    $active.addClass('active'); //Add active class (the $active is declared in the rotateSwitch function)

    $(".steps-content-left").fadeOut(1000); //Remove all active class
	$("#step"+$active.attr("rel")+"-content").fadeIn(1000);
	
	$(".steps-next").hide(); //Remove all active class
	$("#step"+$active.attr("rel")+"_btn").fadeIn(1000);
	
     //Add active class (the $active is declared in the rotateSwitch function)
    //alert(image_reelPosition);
    //Slider Animation
    $(".steps-container").animate({ 
        left: image_reelPosition
    }, 500 , callbackfunc );
}	

increaseProgress = function(){
	var percentage = $active.attr("rel") * 20;
	var stepid = $active.attr("id");
	$("#progress-done").css("width",percentage+"%");
	$("#my-workspace .content-head").css("height",$active.height()+"px");
	//window.location.hash = stepid;	    
}

rotateform(increaseProgress); // runs on load1

// on click
$(".steps-next").click(function(){
	rotateform(increaseProgress);
    return false; //Prevent browser jump to link anchor
});

// on click
$(".steps-prev").click(function(){
	rotateformback(increaseProgress);
    return false; //Prevent browser jump to link anchor
});

// load workspace onclick the featureset
$(".component").click(function(){
	window.location.href = Drupal.settings.basePath +"?q=workspace/1";	
});

$(".tab_content").hide();
$("#tab1_content").fadeIn();

// Your worksspace - tasks tabs click function
$("#workspace-taskbar ul li").click(function(){
	$(".tab_content").hide();
	var clickedIndex = $(this).attr("rel");	
	$("#tab"+clickedIndex+"_content").fadeIn();
	
	$("#workspace-taskbar ul li").removeClass("completed");
	$(this).addClass("completed");
});

Shadowbox.init({
    handleOversize:     "drag",
    displayNav:         false,
    handleUnsupported:  "remove",
    autoplayMovies:     false
});

// jquery tipsy tooltip for form elements
//$('#my-workspace [title]').tipsy({trigger: 'focus', gravity: 'w',fade: false});

// customer form
}); // document ready function
