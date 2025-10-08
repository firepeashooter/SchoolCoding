if [[ -f "$HOME/.trashcan" ]]; then
    echo "$HOME/.trashcan already exists and is a regular file"
    exit 1
fi

if [[ -d "$HOME/.trashcan" ]]; then
    echo "$HOME/.trashcan already exists and is a directory"
    exit 2
fi


mkdir $HOME/.trashcan     #Makes the trashcan directory
chmod 700 ~/.trashcan #Changes permissions to rwx------

touch $HOME/.trashcan/.log #Creates the log file

echo $(date) : $HOME/.trashcan created sucessfully >> $HOME/.trashcan/.log #Logs trashcan created

tempfile=$(mktemp) #Creates a temporary file

mv $tempfile $HOME/.trashcan #Moves temp file to trash

echo $(date) : $tempfile added to trash >> $HOME/.trashcan/.log #Logs the temp file being moved to trash