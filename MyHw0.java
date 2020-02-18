//package gr.akyriakou.hw0;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public class MyHw0 {
	public static void main(String[] args) throws IOException {
		long startTime = System.currentTimeMillis();
		File file = new File(args[0]);
		BufferedReader br = new BufferedReader(new FileReader(file));
		String st;
		List<String> elements = new ArrayList<String>();
		while ((st = br.readLine()) != null)
			elements.add(st);
		Map<String, LinkedHashMap<String, Integer>> map = new HashMap<String, LinkedHashMap<String, Integer>>();
		for (String element : elements) {
			String firstPart = element.substring(0, element.indexOf("|"));
			String secondPart = element.substring(element.indexOf("|") + 1, element.length());
			map.putIfAbsent(firstPart, new LinkedHashMap<String,Integer>());
			map.get(firstPart).putIfAbsent(secondPart, map.get(firstPart).size()+1);
		}
		long endTime = System.currentTimeMillis();
		long duration = (endTime - startTime);
		System.out.println(duration);
		for (String element : elements) {
			String firstPart = element.substring(0, element.indexOf("|"));
			String secondPart = element.substring(element.indexOf("|") + 1, element.length());
			System.out.println(element + "[" + map.get(firstPart).get(secondPart) + " of " + map.get(firstPart).size() + "]");
		}
		endTime = System.currentTimeMillis();
		duration = (endTime - startTime);
		System.out.println(duration);
	}
}
