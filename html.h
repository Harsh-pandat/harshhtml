<!DOCTYPE html>
<html>
<head>
    <title>Customer Support Chat</title>
    <style>
        body {
            font-family: Arial;
        }
        #chatbox {
            width: 300px;
            height: 400px;
            border: 1px solid #ccc;
            position: fixed;
            bottom: 20px;
            right: 20px;
            background: #fff;
            display: flex;
            flex-direction: column;
        }
        #messages {
            flex: 1;
            padding: 10px;
            overflow-y: auto;
        }
        #inputArea {
            display: flex;
        }
        input {
            flex: 1;
            padding: 10px;
        }
        button {
            padding: 10px;
            background: green;
            color: white;
            border: none;
        }
        .bot { color: blue; }
        .user { color: black; text-align: right; }
    </style>
</head>

<body>

<div id="chatbox">
    <div id="messages"></div>
    <div id="inputArea">
        <input type="text" id="userInput" placeholder="Type message...">
        <button onclick="sendMessage()">Send</button>
    </div>
</div>

<script>
function sendMessage() {
    let input = document.getElementById("userInput").value;
    let messages = document.getElementById("messages");

    messages.innerHTML += "<div class='user'>" + input + "</div>";

    let reply = getBotReply(input);
    setTimeout(() => {
        messages.innerHTML += "<div class='bot'>" + reply + "</div>";
    }, 500);

    document.getElementById("userInput").value = "";
}

function getBotReply(input) {
    input = input.toLowerCase();

    if (input.includes("hello")) {
        return "Hello! How can I help you today?";
    }
    else if (input.includes("doctor")) {
        return "You can consult doctors on our website: https://www.safehealthexperience.com";
    }
    else if (input.includes("appointment")) {
        return "To book appointment, visit: https://www.safehealthexperience.com";
    }
    else {
        return "Sorry, I didn't understand. Please visit our website for more help.";
    }
}
</script>

</body>
</html>