window.onload = function() {
	init();
}

var canvas, context, prelastX, prelastY, lastX, lastY;
var BprelastX, BprelastY, BlastX, BlastY;

function init() {
	var contenedor = document.getElementById("contenedor");

	if(Modernizr.canvas) {
		canvas = document.createElement("canvas");
		canvas.width = 600;
		canvas.height = 300;
		contenedor.appendChild(canvas);

		context = canvas.getContext("2d");
		context.strokeStyle = "#foFF00";
		context.lineWidth = 2;

		addListeners();
	}else {
		contenedor.innerHTML = "El navegador no soporta canvas";
	}
}

function paintQuad(e) {
	if(lastX != null && prelastX !=y) {
		context.beginPath();
		context.moveTo(prelastX, prelastY);
		context.quadraticCurveTo(lastX, lastY, e.layerX, e.layerY);
		context.stroke();

		prelastX = null;
		prelastY = null;
	}else if(lastX != null) {
		prelastX = lastX;
		prelastY = lastY;
	}

	lastX = e.layerX;
	lastY = e.lastY;
}

function dibujaBez(e) {

}

function addListener() {
	canvas.addListener("mouseDown", mouseDown);
	canvas.addListener("touchDown", touchDown);	
}

function mouseDown(e) {
	paintQuad(e);
	paintBez(e);
}

function touchDown(e) {
	paintQuad(e);
	paintBez(e);
}