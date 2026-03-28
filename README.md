# Arakne
**Instalación interactiva** | Casa Belgrado, Buenos Aires | 2 y 3 de diciembre de 2022
 
Autoras: [Belén Lesna](https://www.linkedin.com/in/belen-lesna/) · [Sol Represa](https://www.linkedin.com/in/solrepresa/)
 
📎 [Documentación visual del proyecto](https://arakne.hotglue.me/)


## Sinopsis

Desde arriba aparece. Sientes la voz en la cabeza, canal místico de conexión sideral. Te da miedo mirar aunque sabes que está ahí. Las elucubraciones de un animal mitológico te envuelven. Un chip se enciende, los datos transitan. El algoritmo gobierna. Las luces encandilan. Telar lingüístico, sarcófago vivo. El peligro se revela en un mensaje encriptado entre las conexiones que nos sostienen. Mandatos intergeneracionales, propagandas de neón. La reiteración de la copia. No poder dejar de mirar. ¿Qué te sujeta a la red? ¿Dónde está el control? Delete al texto. Deshacer el concepto. Destruir el código. Instalación Interactiva.

---
 
## Contexto conceptual
 
Arakne toma su nombre del mito narrado en las *Metamorfosis* de Ovidio (8 d.C.): Aracne, una tejedora mortal, desafía a Atenea representando en su tapiz los abusos de los dioses sobre las mujeres. Atenea, enfurecida, la transforma en araña, condenándola a tejer eternamente fuera del lenguaje.
 
Las lecturas feministas del mito —como la de Maya (2019)— enfatizan el papel de Aracne como figura de protesta contra la autoridad. Su habilidad para tejer una contranarrativa al texto teocrático de Atenea convierte el mito en una figuración de la relación de producción de la mujer con la cultura dominante: una artista que denuncia desde el margen y es castigada por ello.
 
La instalación actualiza esta tensión trasladándola al presente tecnológico. El nido incubador y la telaraña funcionan como metáforas de las redes de vigilancia y control que nos envuelven: la palabra "ctrl" escrita en hilo fluorescente sobre la telaraña opera como signo doble —el atajo de teclado que gobierna nuestras acciones digitales y el control social que se teje de forma invisible—. La canción infantil "Rolla rolla" suena sobre ecos de un campo de batalla, superponiendo la inocencia del juego con la violencia estructural. La obra interpela al visitante con una pregunta: *¿qué te sujeta a la red?*
 
---
 
## Experiencia del visitante
 
Una atmósfera sonora de murmullos y el sonido del módem dial-up envuelve al público al entrar al salón. La iluminación tenue hace resaltar el monstruoso nido que pende del centro de la habitación. Pequeños huevos iluminados desde su interior revelan cientos de arañas siendo incubadas.
 
Al acercarse, el sensor de distancia en la base del nido detecta la presencia del cuerpo. El nido reacciona: las luces cálidas se apagan y se enciende un efecto estroboscópico violento. La atmósfera muta a una escena caótica con chillidos y gritos afónicos.
 
Pasado un tiempo, el nido vuelve al reposo. La atención se desplaza hacia la pared lateral, donde aparece iluminada con luz ultravioleta la palabra "ctrl" escrita con letras fluorescentes sobre una enorme telaraña de lana. Suena la canción infantil "Rolla rolla" con gran reverberación, sobre ecos de un campo de batalla. A los pies de la telaraña, un sillón ofrece stickers para que les visitantes se lleven como distintivo de la experiencia.
 
---
## Arquitectura técnica
 
La instalación se compone de dos dispositivos conectados mediante una red WiFi local (protocolo ESP-NOW o TCP según versión):
 
### Diagrama general
 
```
┌─────────────────────┐       WiFi local       ┌──────────────────────┐
│       NIDO           │ ──────────────────────▶ │     TELARAÑA          │
│  (centro del salón)  │     señal de disparo    │  (pared lateral)      │
│                      │                         │                       │
│  ESP32 NodeMCU       │                         │  ESP32 NodeMCU        │
│  Sensor HC-SR04      │                         │  ├─ LEDs UV 5mm       │
│  ├─ 5× tiras blanco  │                         │  ├─ Tira UV CINUV5050 │
│    cálido (5 LEDs)   │                         │  └─ Conexión serial   │
│  ├─ 2× tiras color   │                         │     a PC (Processing) │
│    (4 LEDs c/u)      │                         │                       │
│  └─ Tira LED 3528    │                         │  PC ──▶ Audio         │
│    blanco frío       │                         │                       │
└─────────────────────┘                          └──────────────────────┘
```


### Nido (dispositivo emisor)
 
| Componente | Modelo / Especificación |
|---|---|
| Microcontrolador | NodeMCU ESP32 |
| Sensor de distancia | HC-SR04 (ultrasónico) |
| Iluminación reposo | 5 tiras × 5 LEDs blanco cálido (monocromáticas) |
| Iluminación color | 2 tiras × 4 LEDs verde y rojo (monocromáticas) |
| Iluminación activación | Tira LED blanco frío modelo 3528 (efecto estroboscópico) |

### Telaraña (dispositivo receptor)
 
| Componente | Modelo / Especificación |
|---|---|
| Microcontrolador | NodeMCU ESP32 |
| Iluminación UV | 2 tiras de LEDs ultravioleta 5mm ultrabrillantes |
| Iluminación UV (tira) | 1 metro de LED UV modelo CINUV5050 |
| Audio | Salida por puerto serie → PC con Processing |


### Esquemas de conexión

*Esquema electrónico del nido:*

<img src = "https://github.com/solrepresa/arakne/blob/main/Imagenes/esquema_nido.png" width="400"/>

 
*Esquema electrónico de la tela de araña:*

<img src="https://github.com/solrepresa/arakne/blob/main/Imagenes/esquema_red.png" width="400"/>

### Estados del sistema

```
REPOSO
  ├─ Nido: luces cálidas encendidas
  ├─ Telaraña: LEDs UV apagados
  └─ Audio: atmósfera de murmullos + módem dial-up
 
ACTIVACIÓN (presencia detectada por HC-SR04)
  ├─ Nido: luces cálidas OFF → luces frías ON (estroboscópico)
  ├─ Telaraña: LEDs UV encendidos → revela "ctrl"
  └─ Audio: chillidos y gritos afónicos
 
POST-ACTIVACIÓN (retorno gradual)
  ├─ Nido: vuelve a reposo
  ├─ Telaraña: LEDs UV encendidos (mantiene)
  └─ Audio: "Rolla rolla" + reverberación sobre ecos de batalla

```
 
---
## Estructura del repositorio
 
```
arakne/
├── nido_v8/              # Código Arduino para el ESP32 del nido
│   └── nido_v8.ino       #   Sensor HC-SR04 + control de LEDs + envío WiFi
├── pared_v5_ESP32/       # Código Arduino para el ESP32 de la telaraña
│   └── pared_v5_ESP32.ino #  Recepción WiFi + control de LEDs UV
├── pared_v5_UNO/         # Versión alternativa para Arduino UNO
│   └── pared_v5_UNO.ino  #   (versión sin WiFi, conexión por cable)
├── Audio/                # Archivos de audio utilizados en la instalación
├── Imagenes/             # Esquemas electrónicos y documentación visual
│   ├── esquema_nido.png
│   └── esquema_red.png
├── LICENSE               # Licencia MIT
└── README.md
```

---
## Replicación y montaje
 
### Requisitos de hardware
 
**Para el nido:**
- 1× NodeMCU ESP32
- 1× Sensor ultrasónico HC-SR04
- 25× LEDs blanco cálido (5 tiras de 5)
- 8× LEDs color (4 verdes + 4 rojos, en 2 tiras)
- 1× Tira LED blanco frío 3528 (largo según estructura del nido)
- Resistencias, cables dupont, protoboard o PCB
- Fuente de alimentación 5V (dimensionar según consumo total de LEDs)
- Estructura física del nido (malla, alambre, materiales orgánicos)
 
**Para la telaraña:**
- 1× NodeMCU ESP32
- 2× Tiras de LEDs UV 5mm ultrabrillantes
- 1× Tira LED UV CINUV5050 (1 metro)
- 1× PC con Processing instalado
- Cable USB para conexión serial ESP32 ↔ PC
- Parlantes o sistema de audio
- Lana para la estructura de la telaraña
- Pintura o hilo fluorescente para escribir "ctrl"
 
### Requisitos de software
 
- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8+ o 2.x)
- Soporte para placas ESP32 en Arduino IDE ([guía de instalación](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html))
- [Processing](https://processing.org/download) (v3.x o 4.x) — para la reproducción de audio
 
### Pasos de instalación
 
1. **Clonar el repositorio:**
   ```bash
   git clone https://github.com/solrepresa/arakne.git
   ```
 
2. **Configurar el nido:**
   - Abrir `nido_v8/nido_v8.ino` en Arduino IDE.
   - Configurar las credenciales WiFi y la IP del receptor en el código.
   - Seleccionar la placa "ESP32 Dev Module" y el puerto serial correspondiente.
   - Cargar el código en el ESP32.
 
3. **Configurar la telaraña (versión ESP32):**
   - Abrir `pared_v5_ESP32/pared_v5_ESP32.ino` en Arduino IDE.
   - Configurar las credenciales WiFi (deben coincidir con las del nido).
   - Cargar el código en el segundo ESP32.
 
4. **Configurar el audio:**
   - Copiar los archivos de la carpeta `Audio/` a la PC conectada a la telaraña.
   - Abrir el sketch de Processing correspondiente (vinculado al puerto serie del ESP32).
   - Verificar que el puerto serie en Processing coincida con el del ESP32 conectado.
 
5. **Montaje físico:**
   - Suspender el nido del techo en el centro del espacio.
   - Ubicar el sensor HC-SR04 en la base del nido, apuntando hacia abajo.
   - Montar la telaraña de lana sobre una pared lateral.
   - Escribir "ctrl" con material fluorescente sobre la telaraña.
   - Posicionar las luces UV para que iluminen la escritura.
 
> **Nota:** La carpeta `pared_v5_UNO/` contiene una versión alternativa para Arduino UNO, pensada para montajes sin conectividad WiFi (comunicación por cable serial directo).
 
---

## Galería
 
📸 Documentación fotográfica y videos disponibles en la [página del proyecto](https://arakne.hotglue.me/).

---
 
## Contexto de exhibición
 
| Dato | Detalle |
|---|---|
| **Evento** | Muestra en Casa Belgrado |
| **Lugar** | Buenos Aires, Argentina |
| **Fecha** | 2 y 3 de diciembre de 2022 |
| **Formato** | Instalación interactiva site-specific |
| **Autoras** | Belén Lesna y Sol Represa |
 
---

## Créditos
 
**Concepto y realización:** Belén Lesna y Sol Represa
 
---
 
## Referencias
 
- Maya, K. (2019). Arachne's Voice: Race, Gender and the Goddess. *Feminist Theology*, 28(1), 52–65. [https://doi.org/10.1177/0966735019859469](https://doi.org/10.1177/0966735019859469)
- Ovidio. (8 d.C.). *Metamorfosis*, Libro VI.
 
---
 
## Tecnologías
 
`ESP32` · `Arduino` · `Processing` · `HC-SR04` · `WiFi` · `LEDs UV` · `Instalación interactiva`
 
---
 
## Licencia
 
Este proyecto está licenciado bajo la [Licencia MIT](LICENSE).

