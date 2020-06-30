public class SingleCharacterEdit {

    public static String singleCharacterEditWillTurnAIntoB(String a, String b) {

        if(a.equals(b)){
            return null;
        }
        else if(((a.length() - b.length()) < -1)){
            return null;
        }
        else if((a.length() - b.length()) > 1){
            return null;
        }
        else if(a.length() == b.length()){
            char x;
            char y;
            int i;
            int count = 0;
            String newWord;
            for( i = 0; i <a.length(); i++){
                x = a.charAt(i);
                y = b.charAt(i);
                if( x != y){
                    newWord = "replace," + i +"," + b.charAt(i);
                    //System.out.println(newWord);
                    count++;
                    if(count > 1){
                        return null;
                    }
                    else{
                        return newWord;
                    }
                }
            }
        }
        else if(a.length() > b.length()){
            char x;
            char y;
            int i;
            int count = 0;
            String newWord;
            for( i = 0; i <a.length(); i++){
                x = a.charAt(i);
                y = b.charAt(i);
                if( x != y){
                    newWord = "remove," + i;
                    //System.out.println(newWord);
                    count++;
                    if(count > 1){
                        return null;
                    }
                    else{
                        return newWord;
                    }
                }
            }
        }
        else if (a.length() < b.length()){
            char x;
            char y;
            int i;
            int count = 0;
            String newWord;
            for( i = 0; i <a.length(); i++){
                x = a.charAt(i);
                y = b.charAt(i);
                if( x != y){
                    newWord = "insert," + i + "," + a.charAt(i);
                    //System.out.println(newWord);
                    count++;
                    if(count > 1){
                        return null;
                    }
                    else{
                        return newWord;
                    }
                }
                else{
                    newWord = "insert," + a.length() + "," + b.charAt(b.length()-1);
                    //System.out.println(newWord);
                    return newWord;
                }
            }
        }
        return null; // this is only here to make it compile
    }

}
