if [[ -f "$HOME/.trashcan" ]]; then
    echo "~/.trashcan already exists and is a regular file"
    exit 1
fi

if [[ -d "$HOME/.trashcan" ]]; then
    echo "~/.trashcan already exists and is a directory"
    exit 2
fi


mkdir ~/.trashcan     #Makes the trashcan directory
chmod 700 ~/.trashcan #Changes permissions to rwx------

touch ~/.trashcan/.log #Creates the log file

echo $(date) : ~/.trashcan created sucessfully >> ~/.trashcan/.log #Logs trashcan created

tempfile=$(mktemp) #Creates a temporary file

mv $tempfile ~/.trashcan #Moves temp file to trash

echo $(date) : $tempfile added to trash >> ~/.trashcan/.log #Logs the temp file being moved to trash