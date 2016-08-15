<?php
include_once 'facebookapi_php5_restlib.php';
require_once('facebook.php');
require_once('facebook_desktop.php');

$api_key = '147de4a26dc0c85c547f0fb87ffd82f1';
$secret  = 'afc71543008a2b512f42417cc10f2057';

echo "api_key=", $api_key, "\n";
echo "api_key=", $secret, "\n";
$facebook = new FacebookDesktop($api_key, $secret);
$auth_token = $facebook->api_client->auth_createToken();    
echo "auth_token='", $auth_token, "'\n";
?>