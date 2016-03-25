package com.simplexsolutionsinc.coresignkernelwrapper;

import android.app.Activity;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

import com.simplexsolutionsinc.coresignkernelwrapper.documents.CSDocument;
import com.simplexsolutionsinc.coresignkernelwrapper.documents.CSDocumentContent;
import com.simplexsolutionsinc.coresignkernelwrapper.documents.CSDocumentID;
import com.simplexsolutionsinc.coresignkernelwrapper.documents.CSDocumentManager;
import com.simplexsolutionsinc.coresignkernelwrapper.documents.CSDocumentParticipantManager;
import com.simplexsolutionsinc.coresignkernelwrapper.documents.CSPDF;
import com.simplexsolutionsinc.coresignkernelwrapper.session.CSSession;
import com.simplexsolutionsinc.coresignkernelwrapper.session.CSUser;
import com.simplexsolutionsinc.coresignkernelwrapper.session.CSUserKeys;

public class MainActivity extends Activity implements OnClickListener
{

	static
	{
		System.loadLibrary("crystax");
		System.loadLibrary("gnustl_shared");

		System.loadLibrary("CoreSignKernel");
		System.loadLibrary("CoreSignKernelWrapper");
	}
	Button login, logout, startSync, stopSync, create, remove, getIDs, getDocument, pdf;
	final String prKey = "-----BEGIN ENCRYPTED PRIVATE KEY-----\nMIIFDjBABgkqhkiG9w0BBQ0wMzAbBgkqhkiG9w0BBQwwDgQIk2Ek+sTI8YkCAggA\nMBQGCCqGSIb3DQMHBAihTtYm7c7wXwSCBMiZ0/Fdznl3+JrZEq0XleJ14mz1WFfl\n58DTTSixhlLlcVVr17SYpAQZ6NivhJ8myJv7Scu2pJA1/L7jSCH3d/5vSEHNL8B0\nOFTWOEj5n6RoWsxlhIYhvi6nVYh9/1Q/ndqVnUwL76jkHzBX7AY9PfE71EFVnQ2a\nnnEXLAFDo7RQfmHaTQCojHf8hvVeIBedpU+DcXLhkH61XcsYZ+ENRgZwUanYcVaT\nrWFqoF5Y3fMabATuocpj6LG0B0Z1CVl9KM+aIuQUL8GQ3mXxoWKTWtgknezlufyR\nTBqyasP0b9HvZiOGY+1b7Ketevmsy7I8cpW1usjPfZbHL0s5s1CD/UsCwhARfiFd\n6FR77AUwXa1GxivTv9s3U7zQWCRehLsYKWeYEKBfQQSPbBJ67auVWNpr4EcimfRL\nb+RwpEhxHopuJoXK7I3cx/GAAtgXW6dRk8WDuXrucvVeD4h2iawT+NzR5gukoRR8\nRI3iXEjak9SvWeIkF+0TzXuZhy0OazhHcqS/5w2hN4VZy5eHD1uN17pgIHO7L2En\n1fNJwqVpwUdwOrBrHo2j84hhsnjCjc3kcIbo9zSvgfLfiziqFxpYVs9t6MI9GMZO\nfHf1cK3Y+aucozq+LMk4L0jq+g+4lZ6pns43vnSVW76A47taaPbp058DDlDbucm1\ndDz22+ai2LA5I7HYjv0+YAxzF1v0PhRiFamt50ah1cGBIZrx+1OOn9IWVI60PMIY\nC44ZAtxFrQFZnLtJ7EseB/F5nv9UTZRxkhdN9TU+AJcgTA2QY7cHRqlAscOiPFXn\nxSv+3/LsxTcbqONMk8IFTYRMDKtX78Lw5sUHpwCSXnNtSA4yzkAXjWyzO4bVv5Le\nsDq7T5yTb7jaLmk1TTLQweLZpnfZtoIk6AnaSHp3upIi45RBsWWo8zp1KvYG8TzZ\nEkl3caVfeYjWko1Ig82uoYRTckMDZMJVBrevJDH0M5b9Q3Yn/ZQQXiwXhR35EHja\nRIIFxkm1MKc9tW/UFuzDmPqXcmGq+CS2HHdyC8GlN+H96X6YU+ExyDFqXqSoSvN7\ndDqMG3YkrvvYicvadgFwFniDEOCD9HzwcLNfxob3/7ubV01o8en9Vfp4s4e44WnV\nsHcQXsMJA8+5O+H34wmCgkzD3b0JrQj0STDoTY0jRWi7c5O15xdO+ftx/2cRxMH7\neOaGINPUcHWZ6KX6vN01xUZjnEh3m7rRqCVZvr9xIt5Fmd7KcF1+CsxQWd4H+Qon\nVtnKaHcSLdhaG6XwX278ZfELJzr4M6M4i6HDFJrkyjEbjfzu63pB5tD4ntO2M3I+\niSFb9fny5C/h4Pb/BQaURPfk8f/Y4luz8o/4pKx6AHzmpOVYXp3lKhBjK+8LIoIH\nsI/LFX88TfOhJ6td05QNfGSQDulRTUtGELLOe0avEk4c4qzcd4oVk52HFMDg+qmO\nI8hHX8SPCHgPm9HaMBMjT6vrba7psgsL/K9akpxQNhd9ttc5A40r64piQOXxSULl\nL8IIq3vBgplznTVxmq1Q4ozqDTCdvt9UWxEibZstsyg9a3yFrW0t4IS88oNSPoAA\nGTxHYU0wyQhv0qZJ9n0G5rqfz0seT6g8P81YNbUbP6z6sOmzwioKkkkEMPPERThP\nwJc=\n-----END ENCRYPTED PRIVATE KEY-----\n";
	final String pubKey = "-----BEGIN PUBLIC KEY-----\nMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwwX5LqRmzIoQi4W18isB\nSPsddfoL/kwX7VM+fbsR0RAQ9G9e91DGEQok9t1jNQw8mqGXrnQp/VLA2AZjqJcY\nvFGHtafSQ/HgbodWhoUesc1qzA9AbUFZp0u5ZJS7/cdiTEVelQgvG9p//swcsU8d\nBKZ7ov7FGxxbz1sot5I0L0dNv6YWbOPnncn2zFB4pptdFofLys/KzX963yz1Tyrv\n5e2i07EbAWLD661siytivlnAIkgTRReB9VUH9YEkD9/gJLv1n6Oy/lBqCAH9SXS+\nQAYFpXjQFL6NiqEvMv2+Q1NhU/tnmSuXuyAdTifVb/hRlzMNCmDc9NSfLdGM0OwY\noQIDAQAB\n-----END PUBLIC KEY-----\n";
	final String prKeySalt = "sha256$32768$aV1l41E+FM0RYTYWO+n1yvYm6plcsM+STL7Ne5EyEZ8=";
	CSDocumentID[] IDs;

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		login = (Button) findViewById(R.id.button_in);
		logout = (Button) findViewById(R.id.button_out);
		startSync = (Button) findViewById(R.id.button_start);
		stopSync = (Button) findViewById(R.id.button_stop);
		create = (Button) findViewById(R.id.button_create);
		remove = (Button) findViewById(R.id.button_remove);
		getIDs = (Button) findViewById(R.id.button_getids);
		getDocument = (Button) findViewById(R.id.button_getdoc);
		pdf = (Button) findViewById(R.id.button_pdf);
		CSSession.init();
		Log.v("PATH", Environment.getExternalStorageDirectory().getAbsolutePath());
		// CSSession.setConfig(new CSSessionConfig("1", "Android",
		// getApplicationInfo().dataDir, getApplicationInfo().dataDir));
		// CSSession.setConfig(new CSSessionConfig("1", "Android",
		// Environment.getExternalStorageDirectory().getAbsolutePath() +
		// "/CoreSignTemp",
		// Environment.getExternalStorageDirectory().getAbsolutePath() +
		// "/CoreSignTemp"));
		login.setOnClickListener(this);
		logout.setOnClickListener(this);
		startSync.setOnClickListener(this);
		stopSync.setOnClickListener(this);
		create.setOnClickListener(this);
		remove.setOnClickListener(this);
		getDocument.setOnClickListener(this);
		getIDs.setOnClickListener(this);
		pdf.setOnClickListener(this);

		

		// CSSession.logout();

	}

	@Override
	public void onClick(View v)
	{
		int id = v.getId();

		if (id == R.id.button_in)
		{
			Log.v("CLICK", "LOGIN");
			CSResult result = new CSResult();
			CSUser user = new CSUser(2862315, new CSUserKeys(pubKey, prKey, prKeySalt));
			CSSession.login(user, "123456", result);
			int t = result.getCode();
			Toast.makeText(MainActivity.this, t + "", Toast.LENGTH_SHORT).show();

		}
		if (id == R.id.button_out)
		{
			Log.v("CLICK", "LOGOUT");
			CSResult result = new CSResult();
			CSSession.logout(result);
			int t = result.getCode();
			Toast.makeText(MainActivity.this, t + "", Toast.LENGTH_SHORT).show();
		}
		if (id == R.id.button_create)
		{

			// new AsyncTask<Void, Void, Void>()
			// {
			//
			// int t = -1;
			// @Override
			// protected Void doInBackground(Void... params)
			// {
			//
			// return null;
			// }
			//
			// @Override
			// protected void onPostExecute(Void result)
			// {
			//
			// super.onPostExecute(result);
			//
			// }
			// }.execute();

			Log.v("CLICK", "CREATE");
			CSPDF pdf = new CSPDF();
			pdf.setPath(Environment.getExternalStorageDirectory().getAbsolutePath() + "/1.pdf");
			// pdf.setPassword("1");
			Log.v("PDF PATH", pdf.getPath());
			CSResult result2 = new CSResult();
			CSDocumentID docID = CSDocumentManager.createDocument(pdf, 2, result2);
			int t = result2.getCode();
			Toast.makeText(MainActivity.this, t + "", Toast.LENGTH_SHORT).show();

		}
		if (id == R.id.button_getids)
		{
			Log.v("CLICK", "GET IDs");
			CSResult result = new CSResult();
			IDs = CSDocumentManager.getDocumentsIds(result);
			Log.v("IDs COUNT", IDs.length + "");
			int t = result.getCode();
			Toast.makeText(MainActivity.this, t + "", Toast.LENGTH_SHORT).show();

		}
		if (id == R.id.button_getdoc)
		{
			// new AsyncTask<Void, Void, Void>()
			// {
			//
			//
			// @Override
			// protected Void doInBackground(Void... params)
			// {
			//
			// return null;
			// }
			// }.execute();

			Log.v("CLICK", "GET DOC");
			CSResult result = new CSResult();
			if (IDs == null)
			{
				IDs = CSDocumentManager.getDocumentsIds(result);
			}
			Log.v("IDs COUNT", IDs.length + "");
			CSDocument doc = CSDocumentManager.getDocument(IDs[IDs.length - 1], result);

			Log.v("TAG", doc.getName() + "D");
			int t = result.getCode();
			// Toast.makeText(MainActivity.this, t + "",
			// Toast.LENGTH_SHORT).show();

		}

		if (id == R.id.button_remove)
		{
			System.gc();
			/*
			 * Log.v("CLICK", "REMOVE"); CSResult result = new CSResult();
			 * CSDocumentID[] IDs = CSDocumentManager.getDocumentsIds(result);
			 * Log.v("IDs COUNT", IDs.length + "");
			 * CSDocumentManager.removeDocument(IDs[0], result); int t =
			 * result.getCode(); Toast.makeText(MainActivity.this, t + "",
			 * Toast.LENGTH_SHORT).show();
			 */
		}
		if (id == R.id.button_pdf)
		{
			Log.v("CLICK", "GET PDF");
			CSResult result = new CSResult();
			CSDocumentID[] IDs = CSDocumentManager.getDocumentsIds(result);
			Log.v("IDs COUNT", IDs.length + "");
			CSDocument doc = CSDocumentManager.getDocument(IDs[0], result);
			Log.v("DOC NAME", doc.getName());
			CSDocumentContent content = doc.getContent();

			CSDocumentParticipantManager manager = doc.getParticipantManager();
			Log.v("part count", "" + manager.getParticipantCount());
			CSPDF pdf = content.getPDF();
			Log.v("Password", "PDF: " + pdf.getPassword());

			int t = result.getCode();
			Toast.makeText(MainActivity.this, t + "", Toast.LENGTH_SHORT).show();
		}
	}

	@Override
	public void onBackPressed()
	{

		super.onBackPressed();
		finish();
	}
}
