function Figura (tipo, x, y) {
  this.tipo = tipo;
  this.x  = x;
  this.y  = y;
  this.toString= function() {
    return "FIGURA: Tipo: "+this.tipo+" [x:"+this.x+" , y:"+this.y+"]";
  }
}


function CrearPoblaciónInicial() {
 var individuo = new Array();
 for (var i = 0; i < 5; i++) {
     var tipo = 'círculo';
     var x = Math.random()*100;
     var y = Math.random()*100;
         
     individuo[i] = new Figura(tipo, x, y);
 }
     
 console.log(individuo[1].toString());
}



var img = new Image;
var src = "https://picsum.photos/200/300";
var cvs = document.getElementById('canvas');
var ctx = cvs.getContext('2d');
img.crossOrigin = "Anonymous";
canvas= [];
context= [];
var imgData ;
var nImages= 15 ;
var imageData= [] ;
img.onload = function() {
CrearPoblaciónInicial() ;
  ctx.drawImage( img, 0, 0 );
  imgData= ctx.getImageData(0,0,100,100) ;
  table= document.getElementById('table') ;
for (var i=0; i<nImages;i++) {
    if (i%5==0) {
        row= table.insertRow(table.rows.length) ;
      }
    canvas[i]= document.createElement("canvas") ;
      canvas[i].width= canvas[i].height= "100" ;
      context[i]= canvas[i].getContext('2d') ;
      getImage(context[i]) ;
      //context[i].putImageData(imgData,0,0) ;
      imageData[i]= context[i].getImageData(0,0,100,100) ;
      context[i].font = 'italic 10pt Calibri';
      context[i].fillText(similarity(imgData,imageData[i]),10,95) ;
      row.appendChild(canvas[i]) ;
  }
  croossover(imageData[0], imageData[1]);
}

img.src = src;

function getImage(context) {
nCircles= Math.floor((Math.random() * 3) + 1);
  nLines= Math.floor((Math.random() * 3) + 1);
  nRectangles= Math.floor((Math.random() * 3) + 1);
  
  for (var i=0 ; i<nCircles;i++) {
  x1= Math.floor((Math.random() * 100) + 1);
     y1= Math.floor((Math.random() * 100) + 1);
    fill= "#"+Math.floor((Math.random() * 100) + 1)+Math.floor((Math.random() * 100) + 1)+Math.floor((Math.random() * 100) + 1);
    stroke= "#"+Math.floor((Math.random() * 100) + 1)+Math.floor((Math.random() * 100) + 1)+Math.floor((Math.random() * 100) + 1);
    radius= Math.floor((Math.random() * 20) + 1);
    lineWidth= Math.floor((Math.random() * 5) + 1);
  
  drawCircle(context,x1,y1,radius,fill,3,stroke) ;
  }
  
  for (var i=0 ; i<nLines;i++) {
  x1= Math.floor((Math.random() * 100) + 1);
    x2= Math.floor((Math.random() * 100) + 1);
      y1= Math.floor((Math.random() * 100) + 1);
    y2= Math.floor((Math.random() * 100) + 1);
    stroke= "#"+Math.floor((Math.random() * 100) + 1)+Math.floor((Math.random() * 100) + 1)+Math.floor((Math.random() * 100) + 1);
    lineWidth= Math.floor((Math.random() * 5) + 1);
  
  drawLine(context,x1,y1,x2,y2,lineWidth,stroke) ;
  }
  
  for (var i=0 ; i<nRectangles;i++) {
  x1= Math.floor((Math.random() * 100) + 1);
    x2= Math.floor((Math.random() * 100) + 1);
      y1= Math.floor((Math.random() * 100) + 1);
    y2= Math.floor((Math.random() * 100) + 1);
    fill= "#"+Math.floor((Math.random() * 100) + 1)+Math.floor((Math.random() * 100) + 1)+Math.floor((Math.random() * 100) + 1);
    stroke= "#"+Math.floor((Math.random() * 100) + 1)+Math.floor((Math.random() * 100) + 1)+Math.floor((Math.random() * 100) + 1);
    lineWidth= Math.floor((Math.random() * 5) + 1);
  
    drawRectangle(context,x1,y1,x2,y2,fill,lineWidth,stroke) ;
}
}

function drawRectangle(context,x1,y1,x2,y2,fill,lineWidth,stroke) {
  context.beginPath();
    context.rect(x1, y1, x2, y2);
    context.fillStyle = fill ;
    context.fill();
    context.lineWidth = lineWidth;
    context.strokeStyle = stroke;
    context.stroke();
}

function drawLine(context,x1,y1,x2,y2,lineWidth,stroke) {
  context.beginPath();
    context.moveTo(x1, y1);
    context.lineTo(x2, y2);
    context.lineWidth= lineWidth ;
    context.strokeStyle= stroke ;
    context.stroke();
}

function drawCircle(context, x,y,radius,fill,lineWidth,stroke) {
  context.beginPath();
    context.arc(x, y, radius, 0, 2 * Math.PI, false);
    context.fillStyle = fill;
    context.fill();
    context.lineWidth = lineWidth;
    context.strokeStyle = stroke;
    context.stroke();
}


function similarity(imageData1, imageData2) {
data1= imageData1.data ;
  data2= imageData2.data ;
  suma=0 ;
  for (var i=0;i<data1.length;i+=4) {
    suma+= Math.pow((data1[i]-data2[i]),2);
      suma+= Math.pow((data1[i+1]-data2[i+1]),2);
      suma+= Math.pow((data1[i+2]-data2[i+2]),2);
      
  }
  return Math.pow(suma,1/2) ;
}


function croossover(imageData1, imageData2) {
  data1= imageData1.data ;
  data2= imageData2.data ;
  let newData = imageData1.data;
  for (var i=0;i<data1.length;i+=4) {
    if (Math.random()<0.5) {
      data1[i]= data2[i] ;
      data1[i+1]= data2[i+1] ;
      data1[i+2]= data2[i+2] ;
      // newData[i] = (data1[i]+data2[i]) / 2 ;
    }
  }
  i = 15;
  canvas[i]= document.createElement("canvas") ;
  canvas[i].width= canvas[i].height= "100" ;
  context[i]= canvas[i].getContext('2d') ;
  getImage(context[i]) ;
  //context[i].putImageData(imgData,0,0) ;
  imageData[i]= context[i].getImageData(0,0,100,100) ;
  context[i].font = 'italic 10pt Calibri';
  context[i].fillText(similarity(imgData,imageData[i]),10,95) ;
  row.appendChild(canvas[i]) ;

  return imageData1;
}
