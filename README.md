# 2019_1_d3_ta1_IbagueEdwin_LagunaJuan_SanchezCristian



## Resumen

La tarea consisitió en el desarrollo de un código que permitiera realizar satisfactoriamente una convolución 2D a una imagen seleccionada por los desarrolladores, de esta forma, se obtiene una imagen filtrada que se genera como resultado del proceso. 

*Palabras clave:* Convolución, Matriz, filtro, Hilos, Imagen.

## Objetivo

Realizar la implementación paralela de una convolución 2D.

## Introducción

La convolución es uno de los conceptos más usados en el procesamiento de imagenes, el cual se refiere a las operaciones realizadas en señales para extraer datos significativos.  Los matemáticos usan técnicas de convolución para construir las señales de salida ante cualquier señal de entrada, para ello, hacen uso de la respuesta al impulso proporcionado por el sistema. 

## Procedimiento

Se realizó un programa en c++ que permite leer una imagen de una ruta especifica del computador, para posteriormente aplicarle un filtro cd como mínimo 5x5, esto se hace a partir de convolución 2D.

Posteriormente se realiza la paralelización de datos del procedimimiento mediante hilos, en este caso se usó open mp, lo cual quiere decir que es necesario utilizar #pragma omp parallel for para realizar la implementación. Además se estimó la seccion de código que es paralela y la sección que es secuencial, esto con el fin de calcular el speedup teórico asumiendo hasta 16 hilos para de esa manera hacer una comparación entre el speedup teórico y el real.



## Resultados

La imagen a filtrar se muestra a continuación. 


![lena.pgm](https://github.com/edwinibague/2019_1_d3_ta1_IbagueEdwin_LagunaJuan_SanchezCristian/blob/master/lena.pgm)


la tabla de datos obtenida del speedup teorico y el práctico se muestra a continuación. 

![tabla.png](https://github.com/edwinibague/2019_1_d3_ta1_IbagueEdwin_LagunaJuan_SanchezCristian/blob/master/tabla.png)


La gráfica del speedup se muestra a continuación. 

![speedup.png](https://github.com/edwinibague/2019_1_d3_ta1_IbagueEdwin_LagunaJuan_SanchezCristian/blob/master/speedup.png)


En esta imagen se aprecian dos curvas, la naranja es la ideal, es decir así se comporta el speedup de forma teórica. Por otra parte está la curva azul, la cual representa el speedup real que se satura a partir del sexto hilo, esto quiere decir que a partir de 6 hilos no se puede aumentar más la velocidad de ejecución del programa. 



## Conclusiones

Si el computador tienen solo 4 cores, no tiene sentido implementar mas de 4 hilos, ya que lo que pasa en realidad es que un core está implementando mas de un hilo lo cual, gace que se sature la curva de speedup.


En ocaciones hay secciones de código que no vale la pena paralelizar, esto se debe a que dicha sección es muy rapida o sencilla y se invierte mas tiempo repartiendo la tarea que ejecutandola. 

Para realizar el filtro de cualquier tipo de imagen, es necesario crear una matriz dinamica, ya que de lo contrario al querer filtras imagenes ajenas al proyecto, este no funcionará. 

Durante la implementación de la tarea, se presentaron problemas a la hora de realizar el pragma que permite la paralelización con open mp, esto debido a que era necesario tener claridad a la orade repartir tareas para cada hilo, por lo tanto varia veces se realizó una paralelización incorrecta. 


