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
        return "<html><body><h1>Hello, World!!</body></h1></html>";
        //TODO return proper representation object
        //throw new UnsupportedOperationException();
    }

    /**
     * PUT method for updating or creating an instance of DuplicatesResource
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.TEXT_HTML)
    public void putHtml(String content) {
    }
}
