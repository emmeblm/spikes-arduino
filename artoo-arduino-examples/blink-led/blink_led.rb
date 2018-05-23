require 'artoo'

connection :arduino, :adaptor => :firmata, :port => '/dev/cu.usbmodem1421'
device :board, :driver => :device_info
device :led, :driver => :led, :pin => 13

work do
  puts "Firmware name: #{board.firmware_name}"
  puts "Firmata version: #{board.version}"

  every 1.second do
    led.on? ? led.off : led.on
  end
end
