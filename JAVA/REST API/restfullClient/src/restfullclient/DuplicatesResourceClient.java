/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restfullclient;

import java.util.Scanner;
import javax.ws.rs.ClientErrorException;
import javax.ws.rs.client.Client;
import javax.ws.rs.client.WebTarget;

/**
 * Jersey REST client generated for REST resource:DuplicatesResource
 * [duplicates]<br>
 * USAGE:
 * <pre>
 *        DuplicatesResourceClient client = new DuplicatesResourceClient();
 *        Object response = client.XXX(...);
 *        // do whatever with response
 *        client.close();
 * </pre>
 *
 * @author vishr
 */
public class DuplicatesResourceClient {

    private WebTarget webTarget;
    private Client client;
    private static final String BASE_URI = "http://localhost:8080/restfullapi/webresources";

    public DuplicatesResourceClient() {
        client = javax.ws.rs.client.ClientBuilder.newClient();
        webTarget = client.target(BASE_URI).path("duplicates");
    }

    public String getHtml() throws ClientErrorException {
        WebTarget resource = webTarget;
        return resource.request(javax.ws.rs.core.MediaType.TEXT_HTML).get(String.class);
    }

    public String getResult() throws ClientErrorException {
        WebTarget resource = webTarget;
        return resource.request(javax.ws.rs.core.MediaType.TEXT_PLAIN).get(String.class);
    }

    public String putHtml(Object requestEntity) throws ClientErrorException {
        return webTarget
                .request(javax.ws.rs.core.MediaType.TEXT_HTML)
                .put(javax.ws.rs.client.Entity.entity(requestEntity, javax.ws.rs.core.MediaType.TEXT_PLAIN), String.class);
    }

    public void close() {
        client.close();
    }
    
    public static void main(String args[]){
        DuplicatesResourceClient rs = new DuplicatesResourceClient();
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the array to remove duplicates:");
        String input = s.nextLine();
        rs.putHtml(input);
        System.out.println("After removing duplicates:");
        System.out.println(rs.getResult());
    }
}
