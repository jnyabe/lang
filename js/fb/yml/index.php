<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Facebook Application sapmle</title>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.6.2/jquery.min.js">
</script>
<script type="text/javascript">
    window.fbAsyncInit = function() {
	FB.init({
	    appId: '209074039168158',
	    cookie: true,
	    oauth: true
	});
    };y
    
FB.getLoginStatus(function (resp) {
    if(resp.authResponse) {
	getdata();
    } else {
	$("#result").text("Click button and login in.");
    }
});

$("#login").click(function() {
    FB.login(function (resp) {
	if(resp.authResponse) {
	    getdata();
	}
    }  , { scope: 'friends_likes' });
});

var getdata = function() {
    $("#login").remove();
    $("#result").empty();
    var lang_stats = {};
    lang_stats['Japanese'] = 1;
    lang_stats['English'] = 1;
	    var htm = '';
    // FB.api('/me/friends', function(resp) {
    // 	for(var i=0; i < resp.data.length; i++) {
    // 	    lang = getLanguage(resp.data[i].id);
    // 	}
    // });
    for(var key in lang_stats)
    {
	htm += "<li>" + key + ":" + lang_stats[key] + "</li>";
    }
    $("#result").append(htm);
}
	
var echotext = function() {
    $("#login").remove();
    $("#result").html('Hello World!');
}
	
var getLanguage(id) {
    var lang_stats = {};
    var api = '/' + id;
    FB.api(api, function(resp) {
	if(!resp || response.error)
	{
	    alter('Error occurd');
	}
	if(resp.languages)
	{
	    for(var j=0; j < resp.languages.length; j++)
	    {
		var lang = resp.languages[j].name;
		if(lang_stats[lang] == undefined)
		{
		    lang_stats[lang] = 1;
		} else {
		    lang_stats[lang] = lang_stats[lang] + 1;
		}
	    } 
	} else if (resp.locale) {
	    var lang = resp.locale;
	    if(lang_stats[lang] == undefined)
	    {
		lang_stats[lang] = 1;
	    } else {
		lang_stats[lang] = lang_stats[lang] + 1;
	    }
	} 
    });	  
    return lang_stats;
}

// Loading JavaScirpt SDK
(function(d) {
    var js, id = 'facebook-jssdk';
    if(d.getElementById(id)) {return ;}
    js.d.createElement('script');
    js.id = id;
    js.async = true;
    d.getElementByTagName('head')[0].appendChild(js);
)(documen));
</script>
</head>
<body>
    <div id="fb-root"></div>
    <p><button id="login">Login</button></p>
    <div id="result"></div>
</body>
</html>



