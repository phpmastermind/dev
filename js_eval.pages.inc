<?php

/**
 * @file
 * My Workspace Call backs page callbacks for the JS Eval module.
 */


/**
 * Jaspersoft Evaluation My Workspace.
 */
function js_eval_myworkspace(){
  return theme("js_eval_myworkspace");
}

/**
 * Process variables for js-eval-myworkspace.tpl.php.
 *
 * The $variables array contains the following arguments:
 * - $account
 *
 * @see js-eval-myworkspace.tpl.php
 */	
function template_preprocess_js_eval_myworkspace(&$variables) {
  $form_output = drupal_get_form('js_eval_myworkspace_form','');
  // Collect all profiles to make it easier to print all items at once.
  $variables['js_eval_myworkspace_form'] = $form_output;
}

/**
 * Form builder; The js eval myworkspace form.
 *
 * @ingroup forms
 * @see js_eval_myworkspace_form_validate()
 * @see js_eval_myworkspace_form_submit()
 */
function js_eval_myworkspace_form(&$form_state, $myworkspace = NULL){
  global $user;
  $form = array();
  
  $form['#token'] = $user->uid ? $user->name . $user->mail : '';
  // if myworkspace form is edting place a myworkspace id in hidden field
  if($myworkspace["wid"]!="")
  		$form['wid'] = array('#type' => 'value','#value' => $myworkspace["wid"]);
  
  if($form_state["storage"]["stage"] == 3){
	  
		/*######################### STAGE3 ########################*/
		$options = array('self_service' => t('Self Service'), 'production_reporting' => t('Production Reporting'), 'embedded_external' => t('Embedded External'), 'embedded_internal' => t('Embedded Internal'), 'embedded_external' => t('Embedded External'), 'analytics' => t('Analytics'), 'other' => t('Other'));
		echo $myworkspace["use_option"];
		$form['use_option'] = array('#type' => 'radios',
		  '#title' => t('Select the Use Option that is most appropriate'),
		  '#default_value' => $myworkspace["use_option"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		
		$form['back'] = array('#type' => 'button', '#value' => t('Back'),"#onclick" => 'javascript:history.back(-1);return false;');
		$form['submit'] = array('#type' => 'submit', '#value' => t('Submit'));
			
	}else if($form_state["storage"]["stage"] == 2){
		
		/*######################### STAGE2 ########################*/			
		$options = array('developer' => t('Developer'), 'pro_mgmt' => t('Product Management'), 'dw_mgmt' => t('BI/DW Mgmt')
							, 'eng_mgmt' => t('Eng/Dev Mgmt'), 'lob_mgmt' => t('LOB Mgmt'), 'business_analyst' => t('Business Analyst')
							, 'enterprise_architect' => t('Enterprise Architecht'), 'system_integrator' => t('System Integrator')
		);
		$form['role'] = array('#type' => 'radios',
		  '#title' => t('What role best describes your position?'),
		  '#default_value' => $myworkspace["role"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('embedded' => t('Embedded'), 'standalone' => t('Standalone'), 'not_sure' => t('Not Sure'));
		$form['solution'] = array('#type' => 'radios',
		  '#title' => t('What kind of solution are you planning on'),
		  '#default_value' => $myworkspace["solution"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('win32' => t('Windows 32 Bit'),'win64' => t('Windows 64 Bit'), 'linux/unix32' => t('Linux/Unix 32 Bit'), 'linux/unix64' => t('Linux/Unix 64 Bit') );
		$form['js_reportserver_os'] = array('#type' => 'select',
		  '#title' => t('What Operating System are you installing Jaspersoft Reports Server on?'),
		  '#default_value' => $myworkspace["js_reportserver_os"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('redhatjboss' => t('RedHatJboss'),'ibmwebsphere' => t('IBM Websphere'), 'oracleglassfish' => t('Oracle Glassfish Server')
						, 'oracleweblogic' => t('Oracle Weblogic Server'), 'springsourcetcserver' => t('Spring Source tc server')
		);
		$form['js_reportserver_webserver'] = array('#type' => 'select',
		  '#title' => t('By Default Jaspersoft Reports Server ships with Apache Tomcat. If you really want to use another application server for your evaluation select one of the following:'),
		  '#default_value' => $myworkspace["js_reportserver_webserver"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('oracle' => t('Oracle RDBMS'), 'mssql' => t('Microsoft SQL Server'), 'mysql' => t('My SQL'), 'ibmdb2' => t('IBM DB2')
		);
		$form['js_reportserver_db'] = array('#type' => 'select',
		  '#title' => t('By Default Jaspersoft Reports Server ships with PostgreSQL. If you really want to use another database for the repository for the database select one of the following:'),
		  '#default_value' => $myworkspace["js_reportserver_db"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('win32' => t('Windows 32 Bit'),'win64' => t('Windows 64 Bit'), 'linux/unix32' => t('Linux/Unix 32 Bit'), 'linux/unix64' => t('Linux/Unix 64 Bit') );
		$form['js_ireport_designer_os'] = array('#type' => 'select',
		  '#title' => t('What operating system are you going to install Jaspersoft iReport Designer On?'),
		  '#default_value' => $myworkspace["js_ireport_designer_os"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$form['back'] = array('#type' => 'button', '#value' => t('Back'),"#onclick" => 'javascript:history.back(-1);return false;');
		$form['submit'] = array('#type' => 'submit', '#value' => t('Next'));
		
	}else{
		
		/*######################### STAGE1 BY DEFAULT ########################*/
		$options = array('14' => t('With In 2 Weeks'), '30' => t('With in 1 Month'), '60' => t('With in 2 Months'), '60+' => t('> 2 Months'));
		$form['js_eval_timeframe'] = array('#type' => 'select',
		  '#title' => t('Set some timeframe goals'),
		  '#default_value' => $myworkspace["js_eval_timeframe"],
		  '#required' => TRUE,
		  '#options' => $options
		);
		$options = array('1' => t('Sure, Great Idea'), '0' => t('No Thanks'));
		$form['task_reminder'] = array('#type' => 'radios',
		  '#title' => t('Get email reminders on your tasks'),
		  '#default_value' => $myworkspace["task_reminder"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('1' => t('Yes, that could be helpful'), '0' => t('No Thanks'));
		$form['peer_relationship'] = array('#type' => 'radios',
		  '#title' => t('Set up a Peer Relationship during your evaluation'),
		  '#default_value' => $myworkspace["peer_relationship"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$form['submit'] = array('#type' => 'submit', '#value' => t('Next'));
	}
	
	return $form;
}

/**
 * Submit handler for the myworkspace form.
 *
 */
function js_eval_myworkspace_form_submit($form, &$form_state) {
  global $user,$base_url;
  $admin = user_access('administer users');
  if($form_state['values']['op']){
	$title = "";
	$now = date("YmdHis");
	if($form_state["storage"]["stage"] == 1 || $form_state["storage"]["stage"] == ""){
		$form_state["storage"]["stage"] = 2;
		
		$submitted_data = array(
			"js_eval_timeframe" => $form_state['values']['js_eval_timeframe'],
			"task_reminder" => $form_state['values']['task_reminder'],
			"peer_relationship" => $form_state['values']['peer_relationship']
		);
		// store the values in storage to carry forward the values in next stage
		$form_state["storage"]["submitted_values"] = $submitted_data;
		// encode in json format to store in database
		$myworkspace_data = json_encode($submitted_data);
		
		// check if editing form then update
		if($form_state['values']['wid']){
			// update
			$rs = db_query("UPDATE {js_eval_myworkspace}  SET data='%s' where wid = %d ", $myworkspace_data, $form_state['values']['wid']);
			$_SESSION["myworkspace_id"] = $form_state['values']['wid'];
		}else{
			// insert the myworkspace data
			$rs = db_query("INSERT INTO {js_eval_myworkspace} (uid, title, status, datetime, data) VALUES (%d, '%s', '%s', '%s', '%s')", $user->uid, $title, 1, $now, $myworkspace_data);
			if($rs)
				$last_insert_id = db_last_insert_id('{js_eval_myworkspace}','wid');
			
			// update title
			db_query("UPDATE {js_eval_myworkspace}  SET title='%s' where wid = %d ", "myworkspace_".$last_insert_id , $form_state['values']['wid']);
			
			$_SESSION["myworkspace_id"] = $last_insert_id;
			
		}
		if($rs)
			drupal_set_message("Continue to Stage ". $form_state["storage"]["stage"]);
		else
			drupal_set_message("Error");	
		
	}else if($form_state["storage"]["stage"] == 2){
		
		$form_state["storage"]["stage"] = 3;
		$submitted_data = array(
			"role" => $form_state['values']['role'],
			"solution" => $form_state['values']['solution'],
			"js_reportserver_os" => $form_state['values']['js_reportserver_os'],
			"js_reportserver_webserver" => $form_state['values']['js_reportserver_webserver'],
			"js_ireport_designer_os" => $form_state['values']['js_ireport_designer_os'],
			"js_ireport_designer_db" => $form_state['values']['js_ireport_designer_db']
		);
		
		$new_submitted_data = "";
		// merge previous stage and current stage data
		$new_submitted_data = array_merge($form_state["storage"]["submitted_values"],$submitted_data);
		// store the values in storage to carry forward the values in next stage
		$form_state["storage"]["submitted_values"] = $new_submitted_data;
		// encode in json to save in database 
		$myworkspace_data = json_encode($new_submitted_data);
		// insert the myworkspace data	  	
		$rs = db_query("UPDATE {js_eval_myworkspace}  SET data='%s' where wid = %d ", $myworkspace_data, $_SESSION["myworkspace_id"]);
		if($rs)
			drupal_set_message("Continue to Stage ". $form_state["storage"]["stage"]);
		else
			drupal_set_message("Error");	
			
	}else if($form_state["storage"]["stage"] == 3){
		
		$submitted_data = array("use_option" => $form_state['values']['use_option']);
		$new_submitted_data = "";
		
		// merge previous stage and current stage data
		$new_submitted_data = array_merge($form_state["storage"]["submitted_values"],$submitted_data);
		
		// encode in json to save in database 
		$myworkspace_data = json_encode($new_submitted_data);
		
		$rs = db_query("UPDATE {js_eval_myworkspace} SET data='%s' where wid = %d ", $myworkspace_data, $_SESSION["myworkspace_id"]);
		if($rs){
			unset($form_state["storage"]["stage"]);	
			// Clear the page cache because pages can contain usernames and/or profile information:
		    cache_clear_all();
			
			drupal_set_message("Your Evaluation has been saved successfully");
			// redirect to list page
			$form_state['redirect'] = "js_eval/myworkspace/". $user->uid;
		}else{
			drupal_set_message("Error");	
		}
	}
  }
}


/**
 * Form builder; The js eval myworkspace form.
 *
 * @ingroup forms
 * @see js_eval_myworkspace_form_validate()
 * @see js_eval_myworkspace_form_submit()
 */
function js_eval_myworkspace_edit_form(&$form_state, $myworkspace = NULL){
  global $user;
  $form = array();
  
  $form['#token'] = $user->uid ? $user->name . $user->mail : '';
  // if myworkspace form is edting place a myworkspace id in hidden field
  if($myworkspace["wid"]!="")
  		$form['wid'] = array('#type' => 'value','#value' => $myworkspace["wid"]);
  
		/*######################### STAGE1 BY DEFAULT ########################*/
		$options = array('14' => t('With In 2 Weeks'), '30' => t('With in 1 Month'), '60' => t('With in 2 Months'), '60+' => t('> 2 Months'));
		$form['js_eval_timeframe'] = array('#type' => 'select',
		  '#title' => t('Set some timeframe goals'),
		  '#default_value' => $myworkspace["js_eval_timeframe"],
		  '#required' => TRUE,
		  '#options' => $options
		);
		$options = array('1' => t('Sure, Great Idea'), '0' => t('No Thanks'));
		$form['task_reminder'] = array('#type' => 'radios',
		  '#title' => t('Get email reminders on your tasks'),
		  '#default_value' => $myworkspace["task_reminder"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('1' => t('Yes, that could be helpful'), '0' => t('No Thanks'));
		$form['peer_relationship'] = array('#type' => 'radios',
		  '#title' => t('Set up a Peer Relationship during your evaluation'),
		  '#default_value' => $myworkspace["peer_relationship"],
		  '#options' => $options,
		  '#required' => TRUE
		);
	
		/*######################### STAGE2 ########################*/			
		$options = array('developer' => t('Developer'), 'pro_mgmt' => t('Product Management'), 'dw_mgmt' => t('BI/DW Mgmt')
							, 'eng_mgmt' => t('Eng/Dev Mgmt'), 'lob_mgmt' => t('LOB Mgmt'), 'business_analyst' => t('Business Analyst')
							, 'enterprise_architect' => t('Enterprise Architecht'), 'system_integrator' => t('System Integrator')
		);
		$form['role'] = array('#type' => 'radios',
		  '#title' => t('What role best describes your position?'),
		  '#default_value' => $myworkspace["role"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('embedded' => t('Embedded'), 'standalone' => t('Standalone'), 'not_sure' => t('Not Sure'));
		$form['solution'] = array('#type' => 'radios',
		  '#title' => t('What kind of solution are you planning on'),
		  '#default_value' => $myworkspace["solution"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('win32' => t('Windows 32 Bit'),'win64' => t('Windows 64 Bit'), 'linux/unix32' => t('Linux/Unix 32 Bit'), 'linux/unix64' => t('Linux/Unix 64 Bit') );
		$form['js_reportserver_os'] = array('#type' => 'select',
		  '#title' => t('What Operating System are you installing Jaspersoft Reports Server on?'),
		  '#default_value' => $myworkspace["js_reportserver_os"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('redhatjboss' => t('RedHatJboss'),'ibmwebsphere' => t('IBM Websphere'), 'oracleglassfish' => t('Oracle Glassfish Server')
						, 'oracleweblogic' => t('Oracle Weblogic Server'), 'springsourcetcserver' => t('Spring Source tc server')
		);
		$form['js_reportserver_webserver'] = array('#type' => 'select',
		  '#title' => t('By Default Jaspersoft Reports Server ships with Apache Tomcat. If you really want to use another application server for your evaluation select one of the following:'),
		  '#default_value' => $myworkspace["js_reportserver_webserver"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('oracle' => t('Oracle RDBMS'), 'mssql' => t('Microsoft SQL Server'), 'mysql' => t('My SQL'), 'ibmdb2' => t('IBM DB2')
		);
		$form['js_reportserver_db'] = array('#type' => 'select',
		  '#title' => t('By Default Jaspersoft Reports Server ships with PostgreSQL. If you really want to use another database for the repository for the database select one of the following:'),
		  '#default_value' => $myworkspace["js_reportserver_db"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		$options = array('win32' => t('Windows 32 Bit'),'win64' => t('Windows 64 Bit'), 'linux/unix32' => t('Linux/Unix 32 Bit'), 'linux/unix64' => t('Linux/Unix 64 Bit') );
		$form['js_ireport_designer_os'] = array('#type' => 'select',
		  '#title' => t('What operating system are you going to install Jaspersoft iReport Designer On?'),
		  '#default_value' => $myworkspace["js_ireport_designer_os"],
		  '#options' => $options,
		  '#required' => TRUE
		);
		
		/*######################### STAGE3 ########################*/
		$options = array('self_service' => t('Self Service'), 'production_reporting' => t('Production Reporting'), 'embedded_external' => t('Embedded External'), 'embedded_internal' => t('Embedded Internal'), 'embedded_external' => t('Embedded External'), 'analytics' => t('Analytics'), 'other' => t('Other'));
		$form['use_option'] = array('#type' => 'radios',
		  '#title' => t('Select the Use Option that is most appropriate'),
		  '#default_value' => $myworkspace["use_option"],
		  '#options' => $options,
		  '#required' => TRUE
		);
	
	$form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
	return $form;
}

/**
 * Submit handler for the myworkspace edit form.
 *
 */
function js_eval_myworkspace_edit_form_submit($form, &$form_state) {
  global $user,$base_url;
  $admin = user_access('administer js_eval');
  
  if($form_state['values']['op']){
		$title = "";
		$now = date("YmdHis");
	
		$submitted_data = array(
			"js_eval_timeframe" => $form_state['values']['js_eval_timeframe'],
			"task_reminder" => $form_state['values']['task_reminder'],
			"peer_relationship" => $form_state['values']['peer_relationship'],
			"role" => $form_state['values']['role'],
			"solution" => $form_state['values']['solution'],
			"js_reportserver_os" => $form_state['values']['js_reportserver_os'],
			"js_reportserver_webserver" => $form_state['values']['js_reportserver_webserver'],
			"js_ireport_designer_os" => $form_state['values']['js_ireport_designer_os'],
			"js_ireport_designer_db" => $form_state['values']['js_ireport_designer_db'],
			"use_option" => $form_state['values']['use_option']
		);
		
		// encode in json format to store in database
		$myworkspace_data = json_encode($submitted_data);
		
		// check if editing form then update
		if($form_state['values']['wid']){
			// update
			$rs = db_query("UPDATE {js_eval_myworkspace}  SET data='%s' where wid = %d ", $myworkspace_data, $form_state['values']['wid']);
			$_SESSION["myworkspace_id"] = $form_state['values']['wid'];
			if($rs){
				// Clear the page cache because pages can contain usernames and/or profile information:
				cache_clear_all();
				drupal_set_message("Your Evaluation has been saved successfully");
				// redirect to list page
				$form_state['redirect'] = "js_eval/myworkspace/". $user->uid;
			}else{
				drupal_set_message("Error");	
			}
		}
	}
}


/**
 * Form builder; User myworkspace administration page.
 *
 * @ingroup forms
 * @see myworkspace_user_page_validate()
 * @see myworkspace_user_page_submit()
 */
function myworkspace_list_page() {
  global $user;
  
  $destination = drupal_get_destination();
  
  $result = db_query('SELECT wid, uid, title, status, data, datetime FROM {js_eval_myworkspace} where uid = '.$user->uid.' ORDER BY wid');
  $rows = array();
  $status = array(t('Inactive'), t('active'));
  while ($myworkspace = db_fetch_object($result)){
    $rows[] = array(check_plain($myworkspace->title), $status[$myworkspace->status], $myworkspace->datetime, l(t('edit'), 'js_eval/myworkspace/'.$user->uid.'/edit/'. $myworkspace->wid, array('query' => $destination)),
	 l(t('delete'), 'js_eval/myworkspace/'.$user->uid.'/delete/'. $myworkspace->wid, array('query' => $destination)));
  }
  $header = array(t('Title'), t('Status'), t('Created'), array('data' => t('Operations'), 'colspan' => 2));

  return theme('table', $header, $rows);
}


/**
 * My Workspace delete page.
 */
function js_eval_myworkspace_delete_form(&$form_state, $myworkspace) {
  global $user;	
  $form['myworkspace'] = array(
    '#type' => 'value',
    '#value' => $myworkspace,
  );

  return confirm_form($form, t('Are you sure you want to delete %myworkspace?', array('%myworkspace' => $myworkspace['title'])), 'js_eval/myworkspace/'.$user->uid, t('This action cannot be undone.'), t('Delete'), t('Cancel'));
}

/**
 * Process category delete form submission.
 */
function js_eval_myworkspace_delete_form_submit($form, &$form_state) {
  $myworkspace = $form_state['values']['myworkspace'];
  db_query("DELETE FROM {js_eval_myworkspace} WHERE wid = %d", $myworkspace['wid']);
  drupal_set_message(t('Evaluation %myworkspace has been deleted.', array('%myworkspace' => $myworkspace['title'])));
  //watchdog('mail', 'Evaluation form: myworkspace %myworkspace deleted.', array('%myworkspace' => $myworkspace['title']), WATCHDOG_NOTICE);

  $form_state['redirect'] = 'js_eval/myworkspace/'.$user->uid;
  return;
}
