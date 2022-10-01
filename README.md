Thingspeak é uma plataforma que recebe dados de forma remota, esses dados devem estar conectados a internet, pois enviamos os dados através das requisições HTPP e MQTT

Como configurar e utilizar o Thingspeak ?
Primeiramente você deve criar sua conta, utilize o link abaixo para isso:
https://thingspeak.com/login?skipSSOCheck=true

Agora que você já criou sua conta e está logado ao site, é necessario que você clique em "Channels",  localizado no canto superior esquerdo.

![image](https://user-images.githubusercontent.com/85004422/193429115-31a133a5-42e5-4d54-ac66-11be0c69ded4.png)


em seguida clique em "My Channels" e então em "New Channel",  aqui é onde configuraremos nossa API. Marque   as caixinhas ao lado do field 1 e field 2, as outras caixinhas devem estar desabilitadas, se não estiverem, desabilite-as, em seguida renomei o fied 1 para temperatura e o field 2 para umidade, não se esqueça também de colocar um nome bacana para sua API.

![image](https://user-images.githubusercontent.com/85004422/193429254-59e58e24-76a2-431e-a124-c6bb3948052c.png)

após esses passos, clique em "Save Channel", no canto inferior esquerdo.

você será redirecionado para uma página identica  a da print: 

![image](https://user-images.githubusercontent.com/85004422/193429481-bdb90258-0402-4c65-a07e-334568281269.png)

Ainda dentro de sua api, você deve clicar na aba "API KEYS", aqui existem os tipos de requests disponiveis para utilizarmos em nossa requisição http:

![image](https://user-images.githubusercontent.com/85004422/193429527-ee8c0582-dee1-4024-b6db-388305f87cde.png)


Agora iremoos configurar nossa esp32, ligar os leds, conectar o sensor ,os relés e   utilizar o codigo desenvolvido acima, copie o código e entre no link abaixo :
https://wokwi.com/projects/343649470761665106

Clique em library mananger, em seguida clique no +  e adicione a biblioteca DHT sensor library for Espx
![image](https://user-images.githubusercontent.com/85004422/193429790-60d9e9ae-621a-402c-b6af-093195386d03.png)

Com isso feito, nosso código já está apto para funcionar, agora volte até nosso código clicando em "sketch.ino"

Você deve montar o circuito como na imagem abaixo :
![image](https://user-images.githubusercontent.com/85004422/193430091-dda05f03-6314-47ee-9f9c-24c7225323a9.png)

Clicando no + você consegue adicionar os mesmos componentes que o meus, deixarei a lista abaixo

# Componentes

- 2 DPDT Relay
- 1 DHT22
- 2 Leds
- 1 Esp32
 
 # Ligação eletrica
 
 sublinharei da mesma cor do fio onde ele deve estar conectado 
 
![Screenshot(3)](https://user-images.githubusercontent.com/85004422/193430630-45ac04f2-b670-480d-9cb6-6f29e792cf3c.png)


 
