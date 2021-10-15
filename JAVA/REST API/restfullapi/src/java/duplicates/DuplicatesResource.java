/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package duplicates;

import javax.ws.rs.core.Context;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.core.MediaType;

/**
 * REST Web Service
 *
 * @author vishr
 */
@Path("duplicates")
public class DuplicatesResource {
    
    @Context
    private UriInfo context;
    static String response = "";
    /**
     * Creates a new instance of DuplicatesResource
     */
    public DuplicatesResource() {
    }

    /**
     * Retrieves representation of an instance of duplicates.DuplicatesResource
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.TEXT_HTML)
    public String getHtml() {
        String getResponse = "<html><body><h2>Java RESTFul Web Service</h2>"
                + "<h3>Digital Assignment - 1</h3>"
                + "<h4>Vishruth Devan(20BCE2953)</h4>"
                + "</body></html>";
        return getResponse;
        //TODO return proper representation object
        //throw new UnsupportedOperationException();
    }

    
    @GET
    @Produces(MediaType.TEXT_PLAIN)
    public String getResult(){
        return response;
    }
    /**
     * PUT method for updating or creating an instance of DuplicatesResource
     * @param content representation for the resource
     * @return 
     */
    @PUT
    @Consumes(MediaType.TEXT_PLAIN)
    @Produces(MediaType.TEXT_HTML)
    public String putHtml(String content) {
        removeDuplicates(content);
        return "<html><body>" +
                "<h1>Finished removing duplicates, use GET to access new array</h1>" +
                "</body></html>";
    }
    
    public void removeDuplicates(String content){
        response = "";
        String arr[] = content.split(" ");
        String temp;
        int mindex;
        for(int i=0; i<arr.length-1; i++){
            mindex = i;
            for(int j=i+1; j<arr.length; j++){
                if(arr[j].compareToIgnoreCase(arr[mindex]) < 0)
                    mindex=j;
            }
            temp = arr[mindex];
            arr[mindex] = arr[i];
            arr[i] = temp;
        }
        
        int b = 0;
        arr[b]=arr[0];
        for (String arr1 : arr) {
            if (!(arr[b].equals(arr1))) {
                b++;
                arr[b] = arr1;
            }
        }
        for(int i=0;i<=b;i++){
            response += " " + arr[i];
        }
    }
}
