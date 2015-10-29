package com.myway;

import android.content.Context;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.KeyEvent;
import android.view.inputmethod.InputMethodManager;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;

public class MGLTextWatcher implements TextWatcher, OnEditorActionListener
{
	private MGLEditText mEditText;
	private String mText;
	
	public MGLTextWatcher(MGLEditText et)
	{
		this.mEditText = et;
	}
	
	private boolean isFullScreenEdit() {
		final TextView textField = mEditText;
		final InputMethodManager imm = (InputMethodManager) textField.getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
		return imm.isFullscreenMode();
	}
	
	@Override
	public void beforeTextChanged(final CharSequence pCharSequence, final int start, final int count, final int after)
	{
		this.mText = pCharSequence.toString();
	}
	
	@Override
	public void onTextChanged(final CharSequence pCharSequence, final int start, final int before, final int count)
	{
		
	}
	
	public void afterTextChanged(final Editable s)
	{
		if (this.isFullScreenEdit())
			return ;
	
		int nModified = s.length() - this.mText.length();
		if (nModified > 0)
		{
			final String insertText = s.subSequence(this.mText.length(), s.length()).toString();
			this.mEditText.GetGLView().insertText(insertText);
		} 
		else
		{
			for (; nModified < 0; ++nModified) {
				this.mEditText.GetGLView().deleteBackward();
			}
		}
		
		this.mText = s.toString();
		if (mText.length() == 0)
		{
			mEditText.removeTextChangedListener(this);
			{
				mEditText.InitForEdit();
				this.mText = " ";
			}
			mEditText.addTextChangedListener(this);
		}
	}
	
	@Override
	public boolean onEditorAction(final TextView pTextView, final int pActionID, final KeyEvent pKeyEvent)
	{
		/*
		if (this.mEditText == pTextView && this.isFullScreenEdit()) {
			// user press the action button, delete all old text and insert new text
			for (int i = this.mOriginText.length(); i > 0; i--) {
				this.mEditText.GetGLView().deleteBackward();
			}
			
			String text = pTextView.getText().toString();

			// Return Pressed
			//
			if (text.compareTo("") == 0) {
				text = "\n";
			}

			if ('\n' != text.charAt(text.length() - 1)) {
				text += '\n';
			}

			final String insertText = text;
			this.mEditText.GetGLView().insertText(insertText);
		}
		*/
		
		return false;
	}
	
}
