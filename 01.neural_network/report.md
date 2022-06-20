# Red Neuronal - Tesla

## Dataset
El dataset que se escogió fue el del precio de las acciones de Tesla (TSLA), el cuál está adjunto en su forma original en el archivo `TSLA.csv`.

## Situación de aprendizaje
Le idea es que la red neuronal fuera capaz de predecir en base a cinco categorias (High, Low, Adjustement at Close, Volumen y Open) si la acción al día siguiente subiría o bajaría de precio.

## Preparación de los datos
Dado que estos se encontraban en números de punto decimal con valores muy altos de miles lo que se hizo fue un método para normalizar los datos, este lleva el nombre de:
```c++
vector<vector<float>> dataNormalization(vector<vector<float>>& data);
```

## Estructura de la red neuronal
La red neuronal es capaz de incorporar n capas ocultas y n cantidad de neuronas, según alcance el poder computacional; extosamente pudimos lograr que esto fuera de esta forma por la forma en cómo está programada.

## Diseño e implementación de la red
Implementamos una red convolucional, esto se dió porque definimos matrices y la neurona es un elemento implicito de la matriz que existe en base a las dimensiones de la matriz.

## Definición de los datos de entrenamiento
Como se mencionó al inicio tenemos cinco categorías principales en base a las cuáles hacemos el entrenamiento y una sola salida que es el precio para en base a él determinar si subirá o bajará, al ya tener los datos normalizados aplicamos la división 70-20-10:
  * 70% de los datos son para entrenamiento.
  * 20% son para cálculo del rendimiento.
  * 10% son para pruebas en situaciones de la vida real.

## Entrenamiento, funcionamiento y graficación
La red es posible entrenarla y usarla, incluso cargarla con pesos ya establecidos para usarla sin necesidad de volver a entrenarla, esto se podrá ver en el video adjunto.

## Video de demostración
Se adjunta respectivo video de nuestro grupo haciendo una demostración de cómo esta funciona en este mismo entregable.