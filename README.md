# Sony FeliCa RC-S380/S integration application

## Development env
- Download FeliCa SDK for RC-S380/S [here](https://www.sony.net/Products/felica/business/products/RC-S380.html#Application) or [here](https://www.sony.net/Products/felica/business/products/ICS-D004.html#Lineup). We got `sdk4nfc_starter207E.zip`
- Unzip downloaded file
- Open project in Visual Studio (2010 or higher). Right-click on project, choose [Properties]
- Menu [Configuration Properties] -> [C/C++] -> [General] -> [Additional Include Directories]: add folder [sdk4nfc_starter207E\FeliCa_Library\include]
- Menu [Configuration Properties] -> [Linker] -> [General] -> [Additional Include Directories]: add folder [sdk4nfc_starter207E\FeliCa_Library\lib\x86]
  Note: we use 32bit dll
- Menu [Configuration Properties] -> [Linker] -> [Input] -> [Additional Dependencies]: add file name [felica.lib]
- Build and run project (Ctrl-F5)


## Deployment
- 