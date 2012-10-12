<?php

/**
 * @file
 * Adds support for sending SMS messages using the Twilio gateway.
 */

function sms_twilio_token_info_alter(&$info) {
  $info['tokens']['sms']['to'] = array(
    'name' => t("To"), 
    'description' => t("The number the SMS was sent to"),
  );
}

function sms_twilio_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'sms' && !empty($data['sms'])) {
    $sms = $data['sms'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'to':
          $replacements[$original] = check_plain($sms['to']);
          break;

      }
    }
  }
  return $replacements;
}

