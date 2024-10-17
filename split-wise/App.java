import java.util.ArrayList;

import models.*;
import service.algo1;

public class App {
    
    private ArrayList<User> users;

    public App(){
        users = new ArrayList<User>();
    }

    // add users
    public void addUser(User user){
        users.add(user);
    }

    // transactions
    public void directTransfer(User user1, User user2, int amount){

        // can use mutex here
        user1.setBalance(user1.getBalance()-amount);
        user2.setBalance(user2.getBalance()+amount);

    }

    // will split for all users in app
    public void splitEqually(User payer, int amount){
        int n = users.size();
        payer.setBalance(payer.getBalance()-(n-1)*(amount/n));
        for(User x: users){
            if(x==payer)    continue;
            x.setBalance(x.getBalance()+amount/n);
        }
    }        
    
    // alogorithm to settle
    public void settle(algo1 algo){
        algo.settle(users);
    }

public static void main(String[] args) {

    App splitwise = new App();

    // add users
    User Angshuman = new User("Angshuman", 0);
    User DJ = new User("DJ", 0);
    User Manas = new User("Manas", 0);

    splitwise.addUser(Angshuman);
    splitwise.addUser(DJ);
    splitwise.addUser(Manas);

    //add transactions
    splitwise.directTransfer(Angshuman, DJ, 1000);
    splitwise.directTransfer(Angshuman, Manas, 600);
    splitwise.splitEqually(DJ, 1200);

    System.out.println("Balance of Angshuman : "+ Angshuman.getBalance());
    System.out.println("Balance of DJ : "+ DJ.getBalance());
    System.out.println("Balance of Manas : "+ Manas.getBalance());



    //settlement - new oass the algo that we need to use - factory design
    algo1 algo = new algo1();
    splitwise.settle(algo);
    
}
}
