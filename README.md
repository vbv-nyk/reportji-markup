
# Reportजी

An automation tool used for report generation.


## Prerequisites

- A linux Environment.
- Packages shown in upcoming sections.
- Basic computing knowledge.
## Installation

Install visual studio code

```bash
sudo apt-get install wget gpg
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" |sudo tee /etc/apt/sources.list.d/vscode.list > /dev/null
rm -f packages.microsoft.gpg
```

```bash
sudo apt install apt-transport-https
sudo apt update
sudo apt install code 
```

Install make

```bash
sudo apt install make
```

Install pdflatex

```bash
sudo apt-get install texlive-latex-base

sudo apt-get install texlive-fonts-recommended

sudo apt-get install texlive-fonts-extra

sudo apt-get install texlive-latex-extra

```


## Deployment

- Clone the Project to your local machine.
- Open vscode inside the Project folder.
- Open new terminal and run the following 

```bash
./compile 
```

- This creates a sample output file
- To add your input, go to input.ji and add the your own output
- Refer the Documentation [Documentation](https://drive.google.com/file/d/1GwvHjS6z90OTkl6ZzwOYGQAeSDkVQKI0/view?usp=sharing).
Once you have added the contents run the following
```bash
./compile 
```
If you encounter any bugs ,run   
```bash
pdflatex output.tex
```
Press Enter If the routine halts during the execution till the pdf is generated

Output.pdf is the generated document

Sample of a generated [Report](https://drive.google.com/file/d/1a82tV2CoRL1vR1MRJEJD33zP4bTEAr_W/view?usp=sharing)
