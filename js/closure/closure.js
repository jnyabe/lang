function outer(){
    function inner() {
	alert("hello");
    }
    inner();
}
// inner();
outer();
