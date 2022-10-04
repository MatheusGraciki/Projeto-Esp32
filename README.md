<h1 align="center">Captura de dados do ambiente</h1>

# Descrição do Projeto
<p align="center">O intuito desde projeto é compreender sobre o IOT. Criamos um circuito que é capaz de medir a temperatura e umidade através de um sensor que envia dados para um API, onde nele é possível monitorar em tempo real a entrada de dados através de um gráfico.</p>

Tabela de conteúdos
=================
<p align="center">
 <a href="#para-que-serve-o-thingspeak"> Utilidade da plataforma</a> •
 <a href="#configurando-e-utilizando-o-thingspeak">Configurando a API</a> • 
 <a href="#deploy-e-configuração-do-código">Deploy e Código</a> • 
 <a href="#componentes">Componentes</a> • 
 <a href="#ligação-da-fiação">Fiação</a> • 
 <a href="#autores">Autores</a>
</p>


# Para que serve o ThingSpeak?

Thingspeak é uma plataforma que recebe dados de forma remota, esses dados devem estar conectados à internet, pois enviamos os dados através das requisições HTPP e MQTT, nele é possível visualizar a chegada dos dados em tempo real através de um gráfico pelo site.


# Configurando e utilizando o Thingspeak 

Antes de tudo você deve criar sua conta, utilize o link abaixo para isso: 
https://thingspeak.com/login?skipSSOCheck=true

Agora que você já criou sua conta e está logado ao site, é necessario que você clique em "Channels",  localizado no canto superior esquerdo.

![image](https://user-images.githubusercontent.com/85004422/193429115-31a133a5-42e5-4d54-ac66-11be0c69ded4.png)

Em seguida clique em "My Channels" e então em "New Channel", aqui é onde configuraremos nossa API. Marque as caixinhas ao lado do Field 1 e Field 2, as outras caixinhas devem estar desabilitadas, se não estiverem, desabilite-as, em seguida renomeei o Fied 1 para Temperatura e o Field 2 para Umidade, não se esqueça também de colocar um nome bacana para sua API.


![image](https://user-images.githubusercontent.com/85004422/193429254-59e58e24-76a2-431e-a124-c6bb3948052c.png)

Após esses passos, clique em "Save Channel", no canto inferior esquerdo.


Você será redirecionado para uma página idêntica a imagem a abaixo:


![image](https://user-images.githubusercontent.com/85004422/193429481-bdb90258-0402-4c65-a07e-334568281269.png)

Ainda dentro de sua API, você deve clicar na aba "API KEYS", aqui existem os tipos de requests disponíveis para utilizarmos em nossa requisição http:

![image](https://user-images.githubusercontent.com/85004422/193429527-ee8c0582-dee1-4024-b6db-388305f87cde.png)

# Deploy e configuração do código 
Copiei sua "Write API key" e acesse o link:
https://wokwi.com/projects/343649470761665106

Cole sua "Write API key" onde está marcado em amarelo, atente-se em não apagar o "&", caso contrário o código não funcionará.

![image](https://user-images.githubusercontent.com/85004422/193458795-a04b24b1-da34-4dc3-be13-42605cb8ac76.png)

Clique em Library Mananger, em seguida clique no + e adicione a biblioteca DHT sensor library for ESPx.

![image](https://user-images.githubusercontent.com/85004422/193429790-60d9e9ae-621a-402c-b6af-093195386d03.png)


Se você desejar montar o circuito sozinho, siga a imagem abaixo, utilize os componentes e faça a conexão da fiação:

![image](https://user-images.githubusercontent.com/85004422/193430091-dda05f03-6314-47ee-9f9c-24c7225323a9.png)

Clicando no + você conseguirá adicionar os componentes listados abaixo:

# Componentes

- 2 DPDT Relay
- 1 DHT22
- 2 Leds
- 1 Esp32
 
 # Ligação da fiação
 
 ![image](https://user-images.githubusercontent.com/85004422/193433414-3b6e0040-c85f-44ab-a743-b779394c0b85.png)
 
Com isso feito, nosso código já está apto para funcionar, agora volte até o código clicando em "sketch.ino" e clique em iniciar, agora é possível ver o retorno da temperatura tanto no terminal, quanto no gráfico da API.


![image](https://user-images.githubusercontent.com/85004422/193459134-e4c8d180-7cc1-42d4-bf4a-6e9420be1562.png)

Se o led verde acender, o request está sendo feito com sucesso, caso o led vermelho acenda, algum erro está impossibilitando o request. Caso isso venha acontecer, por gentileza entre em contato que iremos ajudá-lo(a).

![image](https://user-images.githubusercontent.com/85004422/193459301-bcd7480b-c402-49da-a288-f0ec64f4fb42.png)


## Autores
Feito com ❤️ por Matheus Graciki e Victória Fortes 👋🏽 Entre em contato!

[![Linkedin Badge](https://img.shields.io/badge/-Matheus-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/matheus-graciki-303287209/)](https://www.linkedin.com/in/matheus-graciki-303287209/) 
[![Linkedin Badge](https://img.shields.io/badge/-Victória-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/vict%C3%B3ria-fortes-848767180/)](https://www.linkedin.com/in/vict%C3%B3ria-fortes-848767180/) 
[![Gmail Badge](https://img.shields.io/badge/-dev.matheusgraciki@outlook.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:dev.matheusgraciki@outlook.com)](mailto:dev.matheusgraciki@outlook.com)
