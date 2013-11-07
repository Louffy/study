package yyjs;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;

import ruc.irm.similarity.word.CharBasedSimilarity;
import ruc.irm.similarity.word.hownet2.concept.LiuConceptParser;
import ruc.irm.similarity.word.hownet2.concept.XiaConceptParser;

public class test {
	public static void main(String[] args) throws IOException{
		XiaConceptParser xParser = null;
		LiuConceptParser lParser = null;
		CharBasedSimilarity cParser = new CharBasedSimilarity();
		lParser = lParser.getInstance();
		xParser = xParser.getInstance();
		String[] word1 = new String[1000];
		String[] word2 = new String[1000];
		double[] score = new double[1000];
		String data = new String();
		BufferedReader br = new BufferedReader(
				new InputStreamReader(new FileInputStream("/home/zfx/pairs.txt")));
		int i = 0;
		while((data = br.readLine()) != null){
			
			int index = data.indexOf(' ');
			word1[i] = new String(data.substring(0, index));
			word2[i] = new String(data.substring(index + 1));
			//System.out.println("--" + word1[i] + "--" + word2[i] +"--");
			i++;
		}
		int max = 30;
		for(int j = 0; j < 1000; j++){
			score[j] = 5*xParser.getSimilarity(word1[j], word2[j]);
			System.out.println(word1[j] + " " + word2[j] + " " + String.format("%.3f",score[j])+ 
					" " + String.format("%.3f",5*lParser.getSimilarity(word1[j], word2[j]))+
					" " + String.format("%.3f",5*cParser.getSimilarity(word1[j], word2[j])));
		}
		
		
		
	}

}
