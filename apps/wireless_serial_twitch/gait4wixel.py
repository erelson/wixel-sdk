
from tempfile import mkstemp
from shutil import move
from os import remove, close
import os, stat

def replace(file, pattern, subst):
    #Create temp file
    fh, abs_path = mkstemp()
    new_file = open(abs_path,'w')
    old_file = open(file, 'r')
    for line in old_file:
        new_file.write(line.replace(pattern, subst))
    #close temp file
    new_file.close()
    close(fh)
    old_file.close()
    #Remove original file
    remove(file)
    #Move new file
    move(abs_path, file)

myFile = "C:/wixel-sdk/apps/wireless_serial_twitch/gait.h"
fileAtt = os.stat(myFile)[0]

if (not fileAtt & stat.S_IWRITE):
    print "attempting to set writeable.."
    # File is read-only, so make it writeable
    os.chmod(myFile, stat.S_IWRITE)
    
replace(myFile, '<Gait/GaitRunner.h>', '"GaitRunner.h"')
replace(myFile, 'PROGMEM', '')
