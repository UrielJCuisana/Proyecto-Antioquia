# Antioquía: Proyecto-EKKO
Sistema de Monitoreo Ambiental.

Technical Document: https://github.com/UrielJCuisana/Proyecto-Antioquia/raw/main/Archivos%20del%20Proyecto/Documento%20Tecnico%20-%20Proyecto%20EKKO.odt

# Introducción
Este proyecto es una estación meteorológica inalámbrica que utiliza un Arduino Nano y sensores para medir la temperatura, humedad y presión atmosférica. Los datos se transmiten a un receptor Python que los almacena en un archivo CSV y luego los grafica en tiempo real. En este documento, se proporciona una guía para configurar el hardware y el software necesarios para ejecutar este proyecto.

## Requisitos
Para ejecutar este proyecto, se necesitará lo siguiente:

## Configuración de software
Para comenzar, descarga o clona este repositorio en tu computadora.

Abre el archivo Main-Arduino.ino en el IDE de Arduino. Asegúrate de que el puerto y el tipo de placa estén configurados correctamente y carga el programa en el Arduino Nano.
Abre el archivo Adjuntar_CSV.py en un editor de texto y modifica el nombre del archivo CSV y la ruta donde se guardará el archivo según tus necesidades. Este programa permite recolectar datos a través del cable.
Abre el archivo PlotDelCSV1.py en un editor de texto y modifica el nombre del archivo CSV que se leerá y los nombres de las columnas según tus necesidades. Este programa es el principal para el análisis de los datos.
Abre el archivo PlotDelCSV2.py en un editor de texto y modifica el nombre del archivo CSV que se leerá y los nombres de las columnas según tus necesidades. Este programa es secundario y se utiliza en caso de que se necesite analizar los datos de otra manera.
Ejecuta el programa PlotDelCSV1.py en Python. Los datos se leerán desde el archivo CSV y se graficarán en tiempo real.

## Documentos dentro del repositorio

Main-Arduino.ino
Contiene el programa para el Arduino Nano que mide la temperatura, humedad y presión atmosférica a través de los sensores y transmite los datos al módulo inalámbrico NRF24L01. Asegúrate de configurar correctamente los pines para los sensores en el código y cargar el programa en el Arduino Nano.

Esquemática PCB
Proporciona el diseño esquemático para la PCB utilizada en el proyecto. Asegúrate de revisar y comprender la esquemática antes de diseñar y producir tu propia PCB.

Lista de partes
Proporciona una lista detallada de las partes necesarias para construir este proyecto, incluyendo los sensores, componentes electrónicos, módulo inalámbrico y más.

Base teórica
Proporciona una explicación detallada de la teoría detrás de la medición de temperatura, humedad y presión atmosférica y cómo los sensores utilizados en este proyecto funcionan para medir estas variables.

Esquemática del proyecto
Proporciona un diagrama esquemático detallado de las conexiones entre el Arduino Nano, los sensores y el módulo inalámbrico NRF24L01. Asegúrate de seguir este esquema al realizar las conexiones para evitar problemas de compatibilidad.

PlotDelCSV1.py
Este es el programa principal de Python utilizado para recopilar y almacenar datos de los sensores en un archivo CSV. Asegúrate de ejecutar este programa antes de ejecutar el programa PlotFromCSV.py.

PlotDelCSV2.py
Este es un programa adicional de Python utilizado para graficar los datos almacenados en el archivo CSV. Ejecuta este programa después de ejecutar el programa PlotFromCSV.py para visualizar los datos a tiempo real.

Adjuntar_CSV.py
Este programa de Python se utiliza para enviar los datos del archivo CSV a un servidor o para compartirlos en línea. Puedes personalizar este programa según tus necesidades.

Data.CSV
Este archivo CSV contiene datos de prueba que se pueden utilizar para verificar que el programa está funcionando correctamente.

¡Eso es todo! Con la información proporcionada y los archivos incluidos en este repositorio, deberías poder construir y ejecutar con éxito tu propia estación meteorológica inalámbrica. Si tienes alguna pregunta o problema, no dudes en revisar la documentación o en contactar a los creadores del proyecto para obtener ayuda.
