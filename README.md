### Pi Bot Arduino

- Set up to use [platformIO](https://platformio.org/install/cli) instead of default arduino IDE.


#### Getting Started
- Move Copy the contents of platformio.ini.sample to platformio.ini 
- In the platformio.ini file, configure pin numbers defined in the build flags under the common section to match the wiring of your arduino.
- Build and deploy the code to the Arduino by running  `platformio run -t upload` at the root of the project.