
      //creating the correct plaintext
     for(int i =0; i< text.length();){ //detecting white space
            
        if(!isspace(text[i])){ //check if whitespace
            
            text[i] =toupper(text[i]);  //convert it to upper case

            if(text[i] =='J'){ //replace J with I
                text[i] ='I';
            }
           if(  i +1 >= text.length()){ //we are at the last word
                result += text[i];
            }else if(text[i] == text[i+1]){  //if