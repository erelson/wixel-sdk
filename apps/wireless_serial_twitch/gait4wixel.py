
from tempfile import mkstemp
from shutil import move
from os import remove, close

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

replace("C:/wixel-sdk/apps/wireless_serial_twitch/gait.h", '<Gait/GaitRunner.h>', '"GaitRunner.h"')
replace("C:/wixel-sdk/apps/wireless_serial_twitch/gait.h", 'PROGMEM', '')
