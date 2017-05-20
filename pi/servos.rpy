# Import necessary files
import serial
from twisted.web.resource import Resource

# Setup Arduino at correct speed
try:
        arduino = serial.Serial('/dev/ttyACM0', 9600)
except:
        arduino = serial.Serial('/dev/ttyUSB1', 9600)

class MoveServo(Resource):
        isLeaf = True
        def render_GET(self,request):
                try:
                		# Send value over serial to the Arduino
                        arduino.write(request.args['value'][0])
                        return 'Success'
                except:
                        return 'Failure'

resource = MoveServo()
