El código debería leer la temperatura de un dallas ds18b20 y compararla con un valor de referencia, en este caso 25ªC.
Si es mayor, apaga el pin de control, si es menor enciende el pin de control.
Conectado a este pin de control habría un relé o mosfet que controla una cama caliente de impresora.

El montaje incluye:
-una ![fuente de alimentacion](ferment-box/images/Power-Supply.jpg) de 12v 10A para alimentación general.  
-un ![step down](ferment-box/images/StepDown.jpg) para alimentar el esp.  
-una ![placa de desarrollo](ferment-box/images/ESP12F.jpg) [esp12f](https://www.wemos.cc/en/latest/d1/d1_mini_3.1.0.html).  
-un mosfet, relé o ssr que funcione a 3v.  
-una ![cama caliente](ferment-box/images/HeatBed.jpg) [RepRap PCB Heatbed MK1](https://reprap.org/wiki/PCB_Heatbed).  
