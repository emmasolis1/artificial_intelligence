let img;
let src;
let cvs;
let ctx;
let canvas;
let context;
let imgData;
let nImages;
let imageData;
let table;


let population;




function inicialize() {

  img = new Image();
  src = "https://picsum.photos/200/300";
  cvs = document.getElementById('canvas');
  ctx = cvs.getContext('2d');
  img.crossOrigin = "Anonymous";
  img.src = src;

  //imgData= ctx.getImageData(0,0,100,100) ;
  table = document.getElementById('table');


  canvas = [];
  context = [];
  nImages = 15;
  imageData = [];

  for (var i = 0; i < nImages; i++) {
    canvas[i] = document.createElement("canvas");
    canvas[i].width = canvas[i].height = "100";
    context[i] = canvas[i].getContext('2d');
    context[i].font = 'italic 10pt Calibri';
  }



  popmax = 15;
  mutationRate = 0.01;
  cantidadFiguras = 16;

  img.onload = function () {
    ctx.drawImage(img, 0, 0);
    imgData = ctx.getImageData(0, 0, 100, 100);

    population = new Population(imgData, mutationRate, popmax, cantidadFiguras);
  }
}




function apply() {

  var target = population.target;


  //Itera 10 veces el algoritmo genetico
  for (var j = 0; j < 10; ++j) {

    for (var i = 0; i < nImages; ++i) {
      context[i].clearRect(0, 0, canvas[i].width, canvas[i].height);
    }

    imageData = [];


    for (var i = 0; i < nImages; i++) {
      if (i % 5 == 0) {
        row = table.insertRow(table.rows.length);
      }
      getImage(context[i], i);
      imageData[i] = context[i].getImageData(0, 0, 100, 100);

      population.population[i].calcularAptitud(target, imageData[i]);

      aptitud = population.population[i].getAptitud();
      context[i].fillText(aptitud, 10, 95);
      row.appendChild(canvas[i]);
    }//End of for que dibuja 15 imagenes


    population.seleccion();

  }//End of for(iteraciones del algoritmo)

}//End of apply()




function draw() {


  for (var i = 0; i < nImages; ++i) {
    context[i].clearRect(0, 0, canvas[i].width, canvas[i].height);
  }

  for (var i = 0; i < nImages; i++) {
    if (i % 5 == 0) {
      row = table.insertRow(table.rows.length);
    }
    getImage(context[i], i);
    row.appendChild(canvas[i]);
  }
}



function getImage(context, nDNA) {

  var x1;
  var y1;
  var x2;
  var y2;
  var fill;
  var radius;
  var stroke;
  var lineWidth;

  for (var i = 0; i < population.cantidadFiguras; ++i) {

    x1 = population.population[nDNA].genes[i].x1;
    y1 = population.population[nDNA].genes[i].y1;
    x2 = population.population[nDNA].genes[i].x2;
    y2 = population.population[nDNA].genes[i].y2;
    fill = "#" + population.population[nDNA].genes[i].fR + population.population[nDNA].genes[i].fG + population.population[nDNA].genes[i].fB;
    radius = population.population[nDNA].genes[i].r;
    lineWidth = population.population[nDNA].genes[i].lW;
    stroke = "#" + population.population[nDNA].genes[i].sR + population.population[nDNA].genes[i].sG + population.population[nDNA].genes[i].sB;

    if (population.population[nDNA].genes[i].tipo == 'circle') {

      drawCircle(context, x1, y1, radius, fill, 3, stroke);

    } else if (population.population[nDNA].genes[i].tipo == 'rectangle') {
      drawRectangle(context, x1, y1, x2, y2, fill, lineWidth, stroke);

    } else {

      drawLine(context, x1, y1, x2, y2, lineWidth, stroke);
    }
  }
}




function drawRectangle(context, x1, y1, x2, y2, fill, lineWidth, stroke) {
  context.beginPath();
  context.rect(x1, y1, x2, y2);
  context.fillStyle = fill;
  context.fill();
  context.lineWidth = lineWidth;
  context.strokeStyle = stroke;
  context.stroke();
}

function drawLine(context, x1, y1, x2, y2, lineWidth, stroke) {
  context.beginPath();
  context.moveTo(x1, y1);
  context.lineTo(x2, y2);
  context.lineWidth = lineWidth;
  context.strokeStyle = stroke;
  context.stroke();
}

function drawCircle(context, x, y, radius, fill, lineWidth, stroke) {
  context.beginPath();
  context.arc(x, y, radius, 0, 2 * Math.PI, false);
  context.fillStyle = fill;
  context.fill();
  context.lineWidth = lineWidth;
  context.strokeStyle = stroke;
  context.stroke();
}
