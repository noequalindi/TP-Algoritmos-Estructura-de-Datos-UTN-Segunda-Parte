# TP_AyED_Segunda_Parte
Segunda Parte TP Anual de Algoritmos y Estructura de Datos 2018

Generalidades

Marco contextual del TP

En los últimos años venimos trabajando y proponiendo un enfoque del Trabajo Práctico Anual donde la resolución de cada ejercicio se relacione con una situación de actualidad, particularmente este año vamos a centrarnos en el Mundial de Fútbol Rusia 2018.
Consultas sobre el trabajo práctico

Para consultas puntuales, puede utilizarse el foro disponible en el campus virtual. Por favor, no revelar resoluciones para otros grupos, intentar que las consultas sean de concepto.
Publicación de notas Mediante el código de grupo que reciban, se podrá chequear la nota obtenida en una planilla que se publicará en el campus virtual apenas se haya realizado la corrección.
Instructivo para Algoritmos y Estructura de Datos

Este trabajo práctico está pensado para los cursos ANUALES.

Condición de aprobación

Para aprobar el trabajo práctico se deben realizar correctamente TODOS los ejercicios propuestos utilizando el lenguaje C/C++. Se deben cumplir las fechas de entrega, no cumplirlas significa quedar fuera de la carrera por la Aprobación Directa. Una vez realizada la entrega (completa) si se debe ajustar algo, habrá una instancia de recuperación.
Una vez realizada (y aprobada) cada entrega parcial, se citará al equipo en el día y turno donde cursen la mayor cantidad de integrantes para hacer un coloquio individual sobre la entrega. El coloquio debe aprobarse.
Si se detectase una situación de copia entre grupos, todos los integrantes quedarán automáticamente fuera de la Aprobación Directa.
Se recomienda utilizar notación Camel Case para los identificadores, tanto de variables como de funciones. Asimismo será obligatorio que los nombres de dichos identificadores se consignen en
español; y que las estructuras de datos a utilizar sean las vistas en clase; se rechazarán todas las soluciones bajadas directamente de internet.
Una vez que se haya aprobado TODO el trabajo práctico, se debe entregar una carpeta al docente del curso (1 por equipo) que cuente con:
- Una carátula con los integrantes ACTUALES del equipo y el código de grupo asignado.
- Los instructivos de cada ejercicio impresos.
- Un CD con las entregas realizadas.
No se va a considerar como válido la Aprobación del Trabajo Práctico del año anterior.
Entrega del trabajo práctico
Una vez que llegue la fecha de entrega de cada una de las partes del trabajo práctico, el líder del grupo debe subir al campus virtual un .rar que debe llevar el siguiente nombre: AED-XXXX-PARTE1 o AED-XXXX-PARTE2 según corresponda. Donde XXXX será el código de grupo.
Se debe respetar la siguiente estructura de archivos:
AED-XXXX-PARTEX (.rar)
- Carátula indicando explícitamente los integrantes ACTUALES del grupo.
- Ejercicio X (carpeta)
- Ejercicio X - Instructivo (.pdf)
- Ejercicio X - Codigo (.cpp)
- Ejercicio X - Nombre de Archivo
La estructura de los ejercicios deben repetirse por cada uno. El instructivo comprende:
- Un instructivo de uso para el programa junto con capturas del programa funcionando.
- La justificación de cualquier decisión tomada a la hora de resolver el problema.
- Si el ejercicio tuviese archivos asociados se debe replicar en el documento la estructura de los archivos con los datos que contienen.
Segunda Entrega:
Comprende la segunda parte del trabajo práctico.
La entrega estará habilitada desde el 2 de octubre de 2018 a las 00:00 horas y hasta el 30 de octubre de 2018 a las 23:59 horas.
Si la entrega no respeta lo expuesto arriba, no será considerada y se perderá la posibilidad de la Aprobación Directa.
Parte 2:
Presentación
El objetivo de esta segunda parte es poner en práctica el concepto de Estructuras dinámicas y la combinación de éstas con otras estructuras vistas en la primera parte.
Ejercicios
1) Desarrolle una función para generar un archivo binario con el siguiente diseño, con un registro por cada gol realizado en el mundial:
id_gol
(int)
cod_equipo
(1..32)
fecha (aaaammdd)
nombre_jugador
(20 caracteres)
id_partido
(1..64)
El archivo debe generarse ordenado por los campos cod_equipo y fecha. Teniendo en cuenta que en el mundial se juegan 64 partidos y compiten 32 equipos.
2) Se requiere de una funcionalidad que a partir del procesamiento del archivo se informe por pantalla:
 La cantidad de goles por equipo, indicando el nombre del equipo y la cantidad de goles. Cuál es el patrón algorítmico más adecuado para recorrer y procesar el archivo?
 Un listado con los goleadores por cada fecha y otro con los goleadores del mundial, indicando el nombre de jugador, el equipo y la cantidad de goles.
Por razones de optimización en el uso de recursos computacionales solo se permite una lectura secuencial del archivo generado, para proceder a volcar los datos en un array de 2 dimensiones como se puede apreciar en la imagen siguiente:
jugador
fecha
goles
sgte
Partidos
Equipos
Donde cada elemento de la matriz es un puntero a una lista enlazada, donde a su vez, cada nodo contiene el nombre del jugador y la cantidad de goles que realizó en una fecha determinada.
Desarrollar un algoritmo para insertar los datos en la matriz, recorrer las estructuras e imprimir por pantalla los listados solicitados.
3) Emitir el listado de goles por equipo del punto anterior, indicando el nombre del equipo y la cantidad de goles, ordenado por cantidad de goles utilizando un árbol binario de búsqueda. Se deberán cargar los datos en el mismo y recorrerlo INORDER. Utilizar como material de consulta el documento redactado por el Dr. O. Bruno en su blog: https://droscarbruno.files.wordpress.com/2018/09/arboles.pdf
