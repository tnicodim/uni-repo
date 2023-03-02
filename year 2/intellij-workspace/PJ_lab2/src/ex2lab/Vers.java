package ex2lab;

public class Vers {
    private String vers;
    public int getWords(){
        int words = 1;
        for (int i = 0; i < vers.length(); i++){
            if (vers.charAt(i) == ' ')
                words++;
        }
        return words;
    }
    public int getVowels(){
        String str = vers.toLowerCase();
        int vowels = 0;
        for (int i = 0; i < str.length(); i++){
            if (str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o' || str.charAt(i) == 'u')
                vowels++;
        }
        return vowels;
    }
    public String getAsterisk(String sequence){
        if (vers.substring(vers.length()-sequence.length()) == sequence)
            return " * ";
        else
            return " ";
    }

    public String randomAllCaps(){
        if (Math.random() < 0.1){
            return vers.toUpperCase();
        }
        return vers;
    }

    public String getVers() {
        return vers;
    }

    public Vers(String vers) {
        this.vers = vers;
    }
}
