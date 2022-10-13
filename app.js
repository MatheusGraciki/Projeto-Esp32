function startConnect() {
    // Generate a random client ID
    clientID = "clientID-" + parseInt(Math.random() * 100) + "ioioi&7778sdfasW23";

    // Fetch the hostname/IP address and port number from the form
    host = document.getElementById("host").value;
    port = document.getElementById("port").value;

    // Print output for the user in the messages div
    document.getElementById("messages").innerHTML += '<span>Connecting to: ' + host + ' on port: ' + port + '</span><br/>';
    document.getElementById("messages").innerHTML += '<span>Using the following client value: ' + clientID + '</span><br/>';

    // Initialize new Paho client connection
    client = new Paho.MQTT.Client(host, Number(port), clientID);

    // Set callback handlers
    client.onConnectionLost = onConnectionLost;
    client.onMessageArrived = onMessageArrived;

    client.connect({ 
        onSuccess: onConnect,
    });
}

// Called when the client connects
function onConnect() {
    topic = document.getElementById("topic").value;
    document.getElementById("messages").innerHTML += '<span>Subscribing to: ' + topic + '</span><br/>';
    client.subscribe(topic);
}

// Called when the client loses its connection
function onConnectionLost(responseObject) {
    document.getElementById("messages").innerHTML += '<span>ERROR: Connection lost</span><br/>';
    if (responseObject.errorCode !== 0) {
        document.getElementById("messages").innerHTML += '<span>ERROR: ' + + responseObject.errorMessage + '</span><br/>';
    }
}

// Called when a message arrives
function onMessageArrived(message) {
    let objJson = JSON.parse(message.payloadString)
    spanTemp = document.getElementById("temperatura").innerHTML = 'Temperatura: ' + objJson.temperatura + '°C'
    spanUmi = document.getElementById("umidade").innerHTML = 'Umidade: ' + objJson.umidade + '%'
}
