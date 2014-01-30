window.onload = function() {
	init();
}

var canvas, context;

function init() {
	var contenedor = document.getElementById("contenedor");

	if(Modernizr.canvas) {
		canvas = document.createElement("canvas");
		canvas.width = 600;
		canvas.height = 300;
		contenedor.appendChild(canvas);

		context = canvas.getContext("2d");

		addListeners();
	}else {
		contenedor.innerHTML = "El navegador no soporta canvas";
	}
}

function paintQuad(e) {

}

function addListener() {
	canvas.addListener("mouseDown", mouseDown);
	canvas.addListener("touchDown", touchDown);	
}

function mouseDown(e) {
	paintQuad(e);
}

function touchDown(e) {
	paintQuad(e);
}