# 2019_1_d3_ta1_IbagueEdwin_LagunaJuan_SanchezCristian


## Resumen

La tarea consisitió en el desarrollo de un código que permitiera realizar satisfactoriamente una convolución 2D a una imagen seleccionada por los desarrolladores, de esta forma, se obtiene una imagen filtrada que se genera como resultado del proceso. 

*Palabras clave:* Convolución, Matriz, filtro, Hilos, Imagen.

## Objetivo

Realizar la implementación paralela de una convolución 2D.

## Introducción

La convolución es uno de los conceptos en el procesamiento de imagenes, el cual se refiere a las operaciones realizadas en señales para extraer datos significativos. 


Se realizó un programa en c++ que permite leer una imagen de una ruta especifica del computador, para posteriormente aplicarle un filtro cd como mínimo 5x5, esto se hace a partir de convolución 2D.


## Procedimiento

Se realizó un programa en c++ que permite leer una imagen de una ruta especifica del computador, para posteriormente aplicarle un filtro cd como mínimo 5x5, esto se hace a partir de convolución 2D.

Posteriormente se realiza la paralelización de datos del procedimimiento mediante hilos, en este caso se usó open mp. 


## Conclusiones

Si el computador tienen solo 4 cores, no tiene sentido implementar mas de 4 hilos, ya que lo que pasa en realidad es que un core está implementando mas de un hilo lo cual, gace que se sature la curva de speedup.


En ocaciones hay secciones de código que no vale la pena paralelizar, esto se debe a que dicha sección es muy rapida o sencilla y se invierte mas tiempo repartiendo la tarea que ejecutandola. 





















En esta grafica se puede observar de manera clara, como los nucleos del pc influyen en el rendimiento del mismo,