public class GarbageCol{  
 
               @SuppressWarnings("deprecation")
     protected void finalize() throws Throwable{
         System.out.println("Garbage collected");
  
     }  
     public static void main(String args[]){  
      GarbageCol s1=new GarbageCol();  
      GarbageCol s2=new GarbageCol();  
      s1=null; 
      s2=null; 
      System.gc();  
     
     }  
    }               
