package service;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import models.User;

// algo 1
// we give the lowest negative to highest positive
public class algo1 {

    public void settle(ArrayList<User> users){
        ArrayList<User> postiveBalances = new ArrayList<>();
        ArrayList<User> negativeBalances = new ArrayList<>();

        for(User x: users){
            if(x.getBalance()>0) postiveBalances.add(x);
            if(x.getBalance()<0) negativeBalances.add(x);            
        }

        // sort postive in desc, neg in asc
        Collections.sort(postiveBalances, Comparator.comparingInt(User::getBalance).reversed());
        Collections.sort(negativeBalances, Comparator.comparingInt(User::getBalance));

        while(negativeBalances.size()>0){
            User x = postiveBalances.getFirst();
            User y = negativeBalances.getFirst();
            int x_balance = x.getBalance();
            int y_balance = y.getBalance();
            int net_balance = x_balance+y_balance;
            
            // bigger positive
            if(net_balance>=0){
                x.setBalance(net_balance);
                y.setBalance(0);
                negativeBalances.remove(y);
                System.out.println(x.getName()+" paid "+y.getName()+" : "+Math.abs(y_balance));

                // if zero
                if(net_balance==0){
                    postiveBalances.remove(x);                    
                }
            }
            // bigger negative balance
            else{
                x.setBalance(0);
                postiveBalances.remove(x);
                y.setBalance(net_balance);
                System.out.println(x.getName()+" paid "+y.getName()+" : "+x_balance);
            }
            
        }
    }

}
