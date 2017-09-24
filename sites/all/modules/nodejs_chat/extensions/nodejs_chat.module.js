/**
 * @file nodejs_chat.module.js
 *
 * Node JS Chat Server extension.
 */

exports.setup = function (config) {
  publishMessageToChannel = config.publishMessageToChannel;
  addClientToChannel = config.addClientToChannel;
  sendMessageToBackend = config.sendMessageToBackend;
  channels = config.channels;

  process.on('client-to-channel-message', function (sessionId, message) {
    // Check message type. Prevents the extension from forwarding any message
    // that is not from the nodejs_chat module.
    if (message.type == 'nodejs_chat') {
      console.log('Node JS Chat extension received a "client-message" event. Action: ' + message.action);
      switch (message.action) {
        // When chat is initialised, user needs to be added to the chat Channel.
        case 'chat_init':
          // Validate against the back-end, that the user can be added indeed to
          // the requested channel (if he's not already added).
          if (!channels[message.channel].sessionIds[sessionId]) {
            sendMessageToBackend(
              {
                messageType: 'nodejs_chat_' + message.action,
                channel: message.channel,
                data: message.data
              }, function (error, response, body) {
                var responseData = JSON.parse(body);
                if (responseData.data == true) {
                  addClientToChannel(sessionId, message.channel);

                  // When entering a chat channel, the client might have sent a message
                  // so that users know about this.
                  publishMessageToChannel(message);
                }
              });
          }
          break;
        // Usual message transmission.
        case 'chat_message':
          publishMessageToChannel(message);
          break;
      }
    }
  });

};
