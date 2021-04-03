
function dothings() {
  var data = {'message': "HOLA"}

  console.log('Send');
  
  Pebble.sendAppMessage(data, function(e) {
    console.log('Success');
  }, function(e) {
    console.log('Failed to send data length to Pebble!');
  })

}

Pebble.addEventListener('ready', function() {
  dothings();
});
