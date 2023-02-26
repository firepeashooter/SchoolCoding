import re
import string
from nltk.corpus import stopwords
stop_words = set(stopwords.words('english'))


class AVLNode:
    def __init__(self, word):
        self.right = None
        self.left = None
        self.height
        self.frequency
        self.word = word






class AVLTreeMap:



        
    def parse_file(self, file):
        with open(file, 'r') as input:
            content = input.readlines()

    
        preprocessed = []

        for line in content:
            line = line.strip().lower()
            #remove punctuation
            line = line.translate(str.maketrans('', '', string.punctuation))
            #remove stop words that care no specific meaning
            line = self.remove_stopwords(line)
            #remove numbers
            line = re.sub('/d+', '', line)
            #remove extra white space
            line = re.sub(' +', ' ', line)

            if line:
                preprocessed.extend(line.split(" "))
        
        print(" ".join(preprocessed))

        return preprocessed
    

    def remove_stopwords(self, text):
        return " ".join([word for word in str(text).split() if word not in stop_words])
    



    def load_from_file(self, file_path):
        #get the file from the file path
        file = open(file_path, 'r')

        print(file)

        word_list = self.parse_file(file)


        for item in word_list:

            #if the word is in the tree update the frequency of the node with the word

            #else insert the node where it belongs (by alphabetical)

                #make sure it stays balanced



        #



    def main():

        path = '/home/firepeashooter/Desktop/GitRepos/SchoolCoding'

        my_tree = AVLTreeMap()

        my_tree.load_from_file(path)


