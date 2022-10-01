Thingspeak é uma plataforma que recebe dados de forma remota, esses dados devem estar conectados a internet, pois enviamos os dados através das requisições HTPP e MQTT

Como configurar e utilizar o Thingspeak ?
Primeiramente você deve criar sua conta, utilize o link abaixo para isso:
https://thingspeak.com/login?skipSSOCheck=true

Agora que você já criou sua conta e está logado ao site, é necessario que você clique em "Channels",  localizado no canto superior esquerdo.



em seguida clique em "New Channel",  aqui é onde configuraremos nossa API. Marque   as caixinhas ao lado do field 1 e field 2, as outras caixinhas devem estar desabilitadas, se não estiverem, desabilite-as, em seguida renomei o fied 1 para temperatura e o field 2 para umidade, não se esqueça também de colocar um nome bacana para sua API, após esses passos, clique em "Save Channel", no canto inferior esquerdo.
Na aba "Channels" clique em "My Channels", A API que configuramos deve aparecer aqui, clique nela e você será redirecionado para a uma ama identica abaixo: 
{footoo}
Ainda dentro de sua api, você deve clicar na aba "API KEYS", aqui existem os tipos de requests disponiveis para utilizarmos em nossa requisição http:
{foto}

Agora iremoos configurar nossa esp32, ligar os leds, conectar o sensor ,os relés e   utilizar o codigo desenvolvido acima, copie o código e entre no link abaixo :
https://wokwi.com/
 
