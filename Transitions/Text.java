/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package housepaint;

import java.io.File;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

/**
 *
 * @author usuario
 */
public class Text {
	public void write(String nameFile, String content) {
		File f; //crea un objeto de tipo archivo;
		f = new File(nameFile);

		try {
			FileWriter w = new FileWriter(f);
			BufferedWriter bw = new BufferedWriter(w);
			PrintWriter wr = new PrintWriter(bw);

                        wr.write(content);
			//wr.append(":)");
			wr.close();
			bw.close();
		}catch (Exception e) {
			
		}
	}
        
	public String read(String nameFile, String type) {
            String file = "";
		try {
			FileReader r = new FileReader(nameFile);
			BufferedReader buffer = new BufferedReader(r);

			//System.out.println(buffer.readLine());
                        String temp = "";
			while (temp != null) {
				temp = buffer.readLine();
				if(temp == null) {
					break;
				}
                                file += temp + "\n";
				//System.out.println(temp);
			};
		}catch(Exception e) {
			System.out.println(e.getMessage());
		};
                return file;
	}        
}
