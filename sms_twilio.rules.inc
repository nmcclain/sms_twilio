<?php

/**
 * @file
 * Rules module support 
 */

function sms_twilio_rules_data_info_alter(&$data_info) {
  $data_info['sms']['property info']['to'] = array (
    ['type'] => 'text',
    ['label'] => t('The number the SMS message was sent to'),
  );
}

