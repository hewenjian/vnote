import subprocess
import time
import sys
import re

print('arg len:' + str(len(sys.argv)) + ' ' + str(sys.argv))

while(True):
    process = subprocess.Popen(sys.argv[1:]
                                , stdin=subprocess.PIPE
                                , stdout=subprocess.PIPE
                                , stderr=subprocess.PIPE)
    output = process.communicate()
    print((str(output[0]), str(output[1])))
	
	
    if re.search('up.*to.*date', str(output[0]) + str(output[1]), re.I) is not None:
        break;
    
    time.sleep(0.3)